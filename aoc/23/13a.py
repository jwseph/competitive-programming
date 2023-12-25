from utils import *

everything = read('13.in')

grids = everything.split('\n\n')
arrs = [[list(line) for line in grid.splitlines()] for grid in grids]

def sol(A):
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
        if res: return r+1
    return 100*sol(list(zip(*A)))

res = 0
for arr in arrs:
    res += sol(list(zip(*arr)))
print(res)