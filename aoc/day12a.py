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
    B = list(map(int, other.split(',')))
    A = list(S)
    A.append('.')
    return dfs(A, B, 0)

res = 0
for line in lines:
    res += sol(line)
print(res)