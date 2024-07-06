import requests
from heapq import heappush, heappop

S = requests.get('https://projecteuler.net/resources/documents/0083_matrix.txt').text

A = [list(map(int, line.split(','))) for line in S.split()]
R, C = len(A), len(A[0])

Q = []
V = set()
heappush(Q, (A[0][0], 0, 0))
while Q:
    t, r, c = heappop(Q)
    if (r, c) in V: continue
    V.add((r, c))
    if (r, c) == (R-1, C-1):
        print(t)
    for i, j in [(r-1, c), (r+1, c), (r, c-1), (r, c+1)]:
        if i < 0 or i >= R or j < 0 or j >= C: continue
        heappush(Q, (t+A[i][j], i, j))