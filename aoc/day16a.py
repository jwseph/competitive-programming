from utils import *

A = open('aoc/day16.in').read().splitlines()
R = len(A)
C = len(A[0])

import sys
sys.setrecursionlimit(100000)
V = set()
lit = [[0]*C for r in range(R)]
res = 0
def dfs(r, c, dr, dc):
    global res
    if r < 0 or r >= R or c < 0 or c >= C: return
    if (r, c, dr, dc) in V: return
    V.add((r, c, dr, dc))
    if not lit[r][c]: res += 1
    lit[r][c] = 1
    if A[r][c] == '.':
        dfs(r+dr, c+dc, dr, dc)
    if A[r][c] == '|' and dc != 0:
        dfs(r+1, c, 1, 0)
        dfs(r-1, c, -1, 0)
    if A[r][c] == '-' and dr != 0:
        dfs(r, c+1, 0, 1)
        dfs(r, c-1, 0, -1)
    if A[r][c] == '|' and dc == 0:
        dfs(r+dr, c+dc, dr, dc)
    if A[r][c] == '-' and dr == 0:
        dfs(r+dr, c+dc, dr, dc)
    if A[r][c] == '/':  # 7, 3
        dr, dc = -dc, -dr
        dfs(r+dr, c+dc, dr, dc)
    if A[r][c] == '\\':
        dr, dc = dc, dr
        dfs(r+dr, c+dc, dr, dc)

dfs(0, 0, 0, 1)

print(res)