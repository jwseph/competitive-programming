from utils import *

A = open('aoc/day14.in').read().splitlines()
R = len(A)
C = len(A[0])
A = list(map(list, A))

def shift(A):
    A = A.copy()
    R = len(A)
    C = len(A[0])
    for r in range(R):
        i = 0
        for c in range(C):
            if A[r][c] == '#': i = c+1
            if A[r][c] == 'O':
                A[r][c] = '.'
                A[r][i] = 'O'
                i += 1
    return A

vi = 0
vst = {}
dp = {}
vst[str(A)] = vi
dp[vi] = A
vi += 1
K = 1000000000

while True:
    # N W S E
    A = list(map(list, zip(*A)))
    A = shift(A)
    A = list(map(list, zip(*A)))
    A = shift(A)
    A = list(map(list, zip(*A)))
    for r in range(R): A[r] = A[r][::-1]
    A = shift(A)
    for r in range(R): A[r] = A[r][::-1]
    A = list(map(list, zip(*A)))
    for r in range(R): A[r] = A[r][::-1]
    A = shift(A)
    for r in range(R): A[r] = A[r][::-1]
    if str(A) in vst:
        w = vi-vst[str(A)]
        K = (K-vst[str(A)])%w+vst[str(A)]
        A = dp[K]
        break
    vst[str(A)] = vi
    dp[vi] = A
    vi += 1

res = 0
for r in range(R):
    for c in range(C):
        if A[r][c] == 'O': res += R-r

print(res)