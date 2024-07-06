import requests

S = requests.get('https://projecteuler.net/resources/documents/0082_matrix.txt').text

A = [list(map(int, line.split(','))) for line in S.split()]
R, C = len(A), len(A[0])

res = 10**9
dp = [[0]*C for r in range(R)]
for r in range(R): dp[r][0] = A[r][0]
for c in range(1, C):
    for r in range(R):
        dp[r][c] = A[r][c] + dp[r][c-1]
    for r in range(1, R):
        dp[r][c] = min(dp[r][c], A[r][c] + dp[r-1][c])
    for r in range(R-1)[::-1]:
        dp[r][c] = min(dp[r][c], A[r][c] + dp[r+1][c])
        if c == C-1:
            res = min(res, dp[r][c])

print(res)