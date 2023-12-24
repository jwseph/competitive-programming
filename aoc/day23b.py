from utils import *

A = open('aoc/day23.in').read().splitlines()
R = len(A)
C = len(A[0])

vtx = {}
for r in range(R):
    for c in range(C):
        if A[r][c] == '#': continue
        tmp_adj = (r+1, c), (r, c+1), (r-1, c), (r, c-1)
        adj = 0
        for i, j in tmp_adj:
            if i < 0 or i >= R or j < 0 or j >= C or A[i][j] == '#': continue
            adj += 1
        if adj != 2: vtx[r, c] = len(vtx)

def dfs1(r, c, pr, pc):
    if (r, c) in vtx:
        return vtx[r, c], 0

    tmp_adj = (r+1, c), (r, c+1), (r-1, c), (r, c-1)
    for i, j in tmp_adj:
        if i < 0 or i >= R or j < 0 or j >= C or A[i][j] == '#' or (i, j) == (pr, pc): continue
        u, w = dfs1(i, j, r, c)
        return u, w+1

adj = [[] for _ in range(len(vtx))]

for r in range(R):
    for c in range(C):
        if (r, c) not in vtx: continue
        v = vtx[r, c]
        if (r, c) == (R-1, C-2): res_v = v
        tmp_adj = (r+1, c), (r, c+1), (r-1, c), (r, c-1)
        for i, j in tmp_adj:
            if i < 0 or i >= R or j < 0 or j >= C or A[i][j] == '#': continue
            u, w = dfs1(i, j, r, c)
            adj[v].append((u, w+1))

V = set()

def dfs(i):
    if i == res_v: return 0
    if i in V: return -inf
    V.add(i)
    res = max(w+dfs(j) for j, w in adj[i])
    V.remove(i)
    return res

res = dfs(0)
print(res)