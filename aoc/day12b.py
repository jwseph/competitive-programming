from utils import *

lines = open('aoc/day12.in').read().splitlines()

def sol(line):
    S, other = line.split()
    B = list(map(int, other.split(',')))*5
    A = list(S+'?')*5
    A.pop()
    P = [0]
    for i in range(len(A)): P.append(P[-1] + int(A[i] == '.'))
    @cache
    def dfs(i, j):
        if i >= len(A): return int(j == len(B))
        res = 0
        if A[i] != '#': res += dfs(i+1, j)
        if j < len(B) and i+B[j] <= len(A) and P[i+B[j]]-P[i] == 0 and not (i+B[j] < len(A) and A[i+B[j]] == '#') and not (i > 0 and A[i-1] == '#'):
            res += dfs(i+B[j]+1, j+1)
        return res
    return dfs(0, 0)

res = 0
for line in lines:
    res += sol(line)
print(res)