from utils import *

lines = open('aoc/day18.in').read().splitlines()

r = c = 0
mr = mc = MR = MC = 0
for line in lines:
    a, b, color = line.split()
    b = int(b)
    if a == 'R': c += b
    if a == 'L': c -= b
    if a == 'U': r -= b
    if a == 'D': r += b
    mr = min(mr, r)
    MR = max(MR, r)
    mc = min(mc, c)
    MC = max(MC, c)

R = MR-mr+3
C = MC-mc+3
r = -mr+1
c = -mc+1
A = [['.']*C for r in range(R)]

for line in lines:
    a, b, color = line.split()
    b = int(b)
    A[r][c] = '#'
    for _ in range(b):
        if a == 'R': c += 1
        if a == 'L': c -= 1
        if a == 'U': r -= 1
        if a == 'D': r += 1
        A[r][c] = '#'

def dfs(r, c):
    if r < 0 or r >= R or c < 0 or c >= C: return
    if A[r][c] != '.': return
    A[r][c] = 'K'
    dfs(r-1, c)
    dfs(r, c-1)
    dfs(r+1, c)
    dfs(r, c+1)

dfs(0, 0)

res = 0
for r in range(R):
    for c in range(C):
        if A[r][c] != 'K': res += 1

print(res)