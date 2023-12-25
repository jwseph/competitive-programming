from utils import *

A = readlines('11.in')

R, C = len(A), len(A[0])

rows = [Counter(A[r])['#'] == 0 for r in range(R)]
cols = [all(A[r][c] == '.' for r in range(R)) for c in range(C)]
V = [(r, c) for r in range(R) for c in range(C) if A[r][c] == '#']

res = 0
for i in range(len(V)):
    for j in range(i+1, len(V)):
        r1, c1 = V[i]
        r2, c2 = V[j]
        if r2 < r1: r1, r2 = r2, r1
        if c2 < c1: c1, c2 = c2, c1

        for r in range(r1, r2): res += rows[r]*999999
        for c in range(c1, c2): res += cols[c]*999999
        res += r2-r1 + c2-c1

print(res)