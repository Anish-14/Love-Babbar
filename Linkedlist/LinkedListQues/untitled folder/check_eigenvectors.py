import numpy as np
from scipy.optimize import root
from pycalphad import Database, variables as v, equilibrium

# --- USER INPUTS ---
# Example for binary alloy (extend to more components as needed)
components = ['CU', 'SI', 'VA']  # 'VA' is the vacancy, required by pycalphad
phases = ['LIQUID', 'FCC_A1']    # Example: liquid and solid phases
dbf = Database('your_database.tdb')  # Path to your TDB file

# Given/assumed values
c_liquid = {'CU': 0.08, 'SI': 0.02}  # Example: 8% Cu, 2% Si
V = 1e-2  # m/s, example growth velocity
V_D = 1e-4  # m/s, example diffusion velocity
V_0 = 1000  # m/s, example speed of sound
R_g = 8.314  # J/(mol K)
gamma = 0.2  # J/m^2, example surface tension
v_mol = 7e-6  # m^3/mol, example molar volume
K = 0  # Assume planar interface for now

# Initial guess for T and C_s
T_guess = 900  # Kelvin
c_s_guess = [0.04, 0.01]  # Initial guess for solid composition

def get_chempots(dbf, comps, phase, T, comp_dict):
    # Returns chemical potentials for each component in the given phase
    eq = equilibrium(dbf, comps, [phase], {v.T: T, v.P: 101325, v.X('CU'): comp_dict['CU'], v.X('SI'): comp_dict['SI']})
    mu = {}
    for el in ['CU', 'SI']:
        mu[el] = float(eq['MU'][0, 0, 0, comps.index(el)])
    return mu

def equations(vars):
    # vars = [T, C_s_CU, C_s_SI]
    T = vars[0]
    c_s = {'CU': vars[1], 'SI': vars[2]}
    c_l = c_liquid

    # Get chemical potentials
    mu_s = get_chempots(dbf, components, 'FCC_A1', T, c_s)
    mu_l = get_chempots(dbf, components, 'LIQUID', T, c_l)

    # Calculate chi_ij and delta_mu
    chi = {}
    delta_mu = {}
    for i in ['CU', 'SI']:
        for j in ['CU', 'SI']:
            delta_mu[i] = mu_s[i] - mu_l[i] - R_g * T * np.log(c_s[i] / c_l[i])
            chi[(i, j)] = np.exp(-(mu_s[j] - mu_l[j] - mu_s[i] + mu_l[i]) / (R_g * T))

    # Ludwig's model (Eq. 16) for each component j
    eqs = []
    for j in ['CU', 'SI']:
        lhs = (c_l[j] - c_s[j]) * V / V_D
        rhs = 0
        for i in ['CU', 'SI']:
            rhs += c_l[i] * c_s[j] - chi[(i, j)] * c_s[i] * c_l[j]
        eqs.append(lhs - rhs)

    # Growth velocity equation (Eq. 20)
    delta_G_DF = sum([c_s[i] * (mu_s[i] - mu_l[i]) for i in ['CU', 'SI']])
    delta_G_K = gamma * v_mol * K
    V_calc = V_0 * (1 - np.exp((delta_G_DF + delta_G_K) / (R_g * T)))
    eqs.append(V - V_calc)

    return eqs

# Initial guess: [T_guess, C_s_CU_guess, C_s_SI_guess]
x0 = [T_guess] + c_s_guess

# Solve the system
sol = root(equations, x0, method='hybr')

if sol.success:
    T_sol = sol.x[0]
    c_s_sol = {'CU': sol.x[1], 'SI': sol.x[2]}
    print(f"Interface temperature: {T_sol:.2f} K")
    print(f"Solid interface composition: {c_s_sol}")
else:
    print("Solution did not converge:", sol.message) 