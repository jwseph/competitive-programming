import requests

S = requests.get('https://projecteuler.net/resources/documents/0081_matrix.txt').text

A = [list(map(int, line.split(','))) for line in S.split()]
R, C = len(A), len(A[0])

for r in range(1, R): A[r][0] += A[r-1][0]
for c in range(1, C): A[0][c] += A[0][c-1]
for r in range(1, R):
    for c in range(1, C):
        A[r][c] += min(A[r][c-1], A[r-1][c])

print(A[-1][-1])