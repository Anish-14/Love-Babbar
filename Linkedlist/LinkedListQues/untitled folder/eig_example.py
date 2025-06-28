import numpy as np
from numpy.linalg import eig

# Let's use a simple 2x2 matrix
A = np.array([[4, 1],
              [1, 3]])

# Get eigenvalues and eigenvectors
eigenvalues, eigenvectors = eig(A)

print("Matrix A:")
print(A)
print("\nEigenvalues (B):")
print(eigenvalues)
print("\nEigenvectors (N):")
print(eigenvectors)

# Verify that these are indeed eigenvalues and eigenvectors
print("\nVerification:")
for i in range(len(eigenvalues)):
    # A * v = λ * v
    left_side = A @ eigenvectors[:, i]
    right_side = eigenvalues[i] * eigenvectors[:, i]
    print(f"\nFor eigenvalue {i+1}:")
    print("A * v =", left_side)
    print("λ * v =", right_side)
    print("Are they equal?", np.allclose(left_side, right_side)) 