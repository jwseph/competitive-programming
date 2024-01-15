import requests

S = requests.get('https://projecteuler.net/resources/documents/0067_triangle.txt').text.strip()

A = [list(map(int, line.split())) for line in S.splitlines()]
N = len(A)

for r in range(1, N):
    for c in range(len(A[r])):
        A[r][c] += max(A[r-1][c] if c < len(A[r-1]) else 0, A[r-1][c-1] if c-1 >= 0 else 0)

print(max(A[-1]))