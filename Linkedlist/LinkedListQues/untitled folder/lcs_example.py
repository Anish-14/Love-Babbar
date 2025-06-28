def lcsRec(s1, s2, m, n, memo):
    # Base case: if either string is empty
    if m == 0 or n == 0:
        return 0
    
    # If we've already calculated this subproblem
    if memo[m][n] != -1:
        return memo[m][n]
    
    # If characters match
    if s1[m-1] == s2[n-1]:
        # Store and return the result
        memo[m][n] = 1 + lcsRec(s1, s2, m-1, n-1, memo)
        return memo[m][n]
    
    # If characters don't match
    memo[m][n] = max(lcsRec(s1, s2, m-1, n, memo),
                     lcsRec(s1, s2, m, n-1, memo))
    return memo[m][n]

# Example usage
s1 = "ABCDGH"
s2 = "AEDFHR"
m, n = len(s1), len(s2)

# Initialize memoization table with -1
memo = [[-1 for _ in range(n+1)] for _ in range(m+1)]

# Find LCS length
result = lcsRec(s1, s2, m, n, memo)
print(f"Length of LCS: {result}")

# Print the memoization table
print("\nMemoization table:")
for row in memo:
    print(row) 