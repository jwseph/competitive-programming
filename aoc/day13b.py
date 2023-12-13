from utils import *

everything = open('aoc/day13.in').read().strip()

grids = everything.split('\n\n')
arrs = [[list(line) for line in grid.splitlines()] for grid in grids]

def sol(A, cur, stop=False):
    R = len(A)
    C = len(A[0])
    for r in range(R-1):
        i = r
        j = i+1
        res = True
        while i >= 0 and j < R:
            if A[i] != A[j]:
                res = False
                break
            i -= 1
            j += 1
        if res and r+1 != cur%100: return r+1
    if stop: return 0
    return 100*sol(list(zip(*A)), cur//100, stop=True)

def sol2(A):
    R =len(A)
    C = len(A[0])
    A = list(map(list, A))
    cur = sol(A, 10**9)
    for r in range(R):
        for c in range(C):
            tmp = A[r][c]
            A[r][c] = {'#': '.', '.': '#'}[tmp]
            dp = sol(A, cur)
            if dp > 0: return dp
            A[r][c] = tmp

res = 0
for arr in arrs:
    res += sol2(list(zip(*arr)))
print(res)