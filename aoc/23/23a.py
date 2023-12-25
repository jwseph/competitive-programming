from utils import *

A = readlines('23.in')

R = len(A)
C = len(A[0])
V = set()

def dfs(r, c):
    if r == R-1 and c == C-2: return 0
    if r < 0 or r >= R or c < 0 or c >= C: return -inf
    if A[r][c] == '#': return -inf
    if (r, c) in V: return -inf
    V.add((r, c))
    if A[r][c] == 'v': res = 1+dfs(r+1, c)
    elif A[r][c] == '>': res =  1+dfs(r, c+1)
    elif A[r][c] == '<': res =  1+dfs(r, c-1)
    elif A[r][c] == '^': res = 1+dfs(r-1, c)
    else:
        res = max(dfs(r+1, c), dfs(r, c+1), dfs(r-1, c), dfs(r, c-1))+1
    V.remove((r, c))
    return res

res = dfs(0, 1)
print(res)