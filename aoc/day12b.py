from utils import *

lines = open('aoc/day12.in').read().splitlines()

def dfs(A, B, i):
    if i == len(A):
        cur = 0
        j = 0
        for c in A:
            if c == '.':
                if cur:
                    if j == len(B) or B[j] != cur: return 0
                    j += 1
                cur = 0
            else:
                cur += 1
        return int(j == len(B))
    if A[i] != '?': return dfs(A, B, i+1)
    res = 0
    A[i] = '#'
    res += dfs(A, B, i+1)
    A[i] = '.'
    res += dfs(A, B, i+1)
    A[i] = '?'
    return res

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