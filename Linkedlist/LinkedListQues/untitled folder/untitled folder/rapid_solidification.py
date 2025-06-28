import numpy as np
from pycalphad import Database, calculate, variables as v
from scipy.optimize import root
import logging

# Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Step 1: Load database and define system
try:
    with open('mmc1.tdb', 'r', encoding='latin-1') as f:
        tdb_content = f.read()
    dbf = Database(tdb_content)
    logger.info("Database 'mmc1.tdb' loaded successfully.")
except FileNotFoundError:
    logger.error("Error: mmc1.tdb not found. Please check the path.")
    exit()
except Exception as e:
    logger.error(f"Error loading database: {e}")
    exit()

# Your ternary components
comps_for_composition = ['AL', 'MG', 'SI']
comps_in_database = ['AL', 'MG', 'SI', 'VA']
phases = ['FCC_A1', 'LIQUID']

c = len(comps_for_composition)
logger.info(f'Number of components: {c}')

# --- Define Constants and Parameters ---
R_g = 8.314  # J/(mol K)
V_growth = 1e-4     # Growth velocity (m/s)
V_D = 1e-3   # Diffusive velocity (m/s)
V_0 = 1000.0 # Speed of sound (m/s)
gamma = 0.5 # Surface tension (J/m^2)
v_mol = 7.0e-6 # Molar volume (m^3/mol)
K = 1.0e7 # Curvature (1/m)
P = 101325  # Pressure in Pa (1 atm)

def get_mu(dbf, all_components, phase, T, P, composition_dict):
    """Get chemical potentials for a phase."""
    try:
        # Create full composition dictionary
        full_composition_dict = composition_dict.copy()
        for comp in all_components:
            if comp not in full_composition_dict:
                if comp == 'VA':
                    full_composition_dict[comp] = 1.0
                else:
                    full_composition_dict[comp] = 0.0

        # Sort components for consistent ordering
        sorted_components = sorted(full_composition_dict.keys())
        points_list = [full_composition_dict[comp] for comp in sorted_components]

        # Calculate chemical potentials
        res = calculate(
            dbf, all_components, phases=[phase], output='MU', T=T, P=P,
            points=np.array([points_list]),
            N=1
        )

        # Extract chemical potentials
        mu = {}
        for comp_name in res.component.values:
            mu[str(comp_name)] = float(res.MU.sel(component=comp_name).values)
        
        logger.debug(f"Chemical potentials for {phase}: {mu}")
        return mu

    except Exception as e:
        logger.error(f"Error in get_mu for phase {phase}: {e}")
        raise

def coupled_equations_ternary(vars):
    """System of equations for ternary system."""
    try:
        # Unpack variables
        T_val = vars[0]
        Cl_star_dict = dict(zip(comps_for_composition, vars[1:c+1]))
        
        # Validate inputs
        if T_val <= 200 or T_val > 3000:
            logger.warning(f"Invalid temperature: {T_val}")
            return [1e10] * (c + 1)

        Cl_star_array = np.array([Cl_star_dict[comp] for comp in comps_for_composition])
        if not np.all(np.isfinite(Cl_star_array)) or abs(np.sum(Cl_star_array) - 1.0) > 1e-9:
            logger.warning(f"Invalid compositions: {Cl_star_dict}")
            return [1e10] * (c + 1)

        logger.info(f"\nIteration with T={T_val:.2f}K, Compositions={Cl_star_dict}")

        # Calculate solid compositions (placeholder - replace with actual model)
        k_values = {'AL': 0.8, 'MG': 0.6, 'SI': 0.2}
        Cs_star_dict = {comp: Cl_star_dict[comp] * k_values.get(comp, 1.0) 
                       for comp in comps_for_composition}

        # Get chemical potentials
        solid_comp = {**Cs_star_dict, 'VA': 1.0}
        liquid_comp = {**Cl_star_dict, 'VA': 1.0}

        mu_s_dict = get_mu(dbf, comps_in_database, 'FCC_A1', T_val, P, solid_comp)
        mu_l_dict = get_mu(dbf, comps_in_database, 'LIQUID', T_val, P, liquid_comp)

        # Calculate arrays
        Cs_star_array = np.array([Cs_star_dict[comp] for comp in comps_for_composition])
        mu_s_array = np.array([mu_s_dict[comp] for comp in comps_for_composition])
        mu_l_array = np.array([mu_l_dict[comp] for comp in comps_for_composition])

        # Calculate delta mu and delta tilde mu
        delta_mu = mu_s_array - mu_l_array
        log_ratio = np.log((Cs_star_array + 1e-12) / (Cl_star_array + 1e-12))
        delta_tilde_mu = delta_mu - R_g * T_val * log_ratio

        # Calculate chi matrix
        chi_ij = np.zeros((c, c))
        for i in range(c):
            for j in range(c):
                chi_ij[i, j] = np.exp(-(delta_tilde_mu[j] - delta_tilde_mu[i]) / (R_g * T_val))

        # Calculate driving forces
        delta_G_DF = np.sum(Cs_star_array * delta_mu)
        delta_G_K = gamma * v_mol * K

        # Calculate residuals
        residuals = []
        
        # Equation (16) residuals
        for i in range(c):
            sum_term = np.sum(Cs_star_array * chi_ij[i, :] * Cl_star_array)
            residual = (Cl_star_array[i] - Cs_star_array[i]) * V_growth / V_D - sum_term
            residuals.append(residual)

        # Equation (20) residual
        residual = V_growth - V_0 * (1.0 - np.exp(-(delta_G_DF + delta_G_K) / (R_g * T_val)))
        residuals.append(residual)

        logger.debug(f"Residuals: {residuals}")
        return residuals

    except Exception as e:
        logger.error(f"Error in coupled_equations_ternary: {e}")
        return [1e10] * (c + 1)

# Initial guess
initial_guess = [850.0, 0.8, 0.1, 0.1]  # [T, Cl_AL, Cl_MG, Cl_SI]

# Solve the system
try:
    logger.info("Starting solver...")
    solution = root(coupled_equations_ternary, initial_guess, method='hybr', 
                   options={'maxfev': 1000, 'xtol': 1e-8})

    if solution.success:
        solved_vars = solution.x
        solved_T = solved_vars[0]
        solved_Cl_star = dict(zip(comps_for_composition, solved_vars[1:c+1]))

        logger.info("\nSolution found:")
        logger.info(f"Interface Temperature: {solved_T:.2f} K")
        logger.info("Interface Liquid Compositions:")
        for comp, val in solved_Cl_star.items():
            logger.info(f"  {comp}: {val:.4f}")

        # Calculate final residuals
        final_residuals = coupled_equations_ternary(solved_vars)
        logger.info(f"Final residuals: {final_residuals}")

    else:
        logger.error("Solver failed to find a solution")
        logger.error(f"Status: {solution.status}")
        logger.error(f"Message: {solution.message}")
        logger.error(f"Function calls: {solution.nfev}")

except Exception as e:
    logger.error(f"Error during solving: {e}") 