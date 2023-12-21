from utils import *

A = open('aoc/day21.in').read().splitlines()
R = len(A)
C = len(A[0])

def sol(stepmax):
    from collections import deque
    q = deque()
    vst = set()

    for r in range(R):
        for c in range(C):
            if A[r][c] == 'S':
                q.append((r, c))
                vst.add((r, c))
    steps = 0
    while len(q) and steps < stepmax:
        for _ in range(len(q)):
            r, c = q.popleft()
            adj = ((r-1, c), (r, c-1), (r+1, c), (r, c+1))
            for i, j in adj:
                if (i, j) in vst: continue
                if A[i%R][j%C] == '#': continue
                vst.add((i, j))
                q.append((i, j))
        steps += 1
    return sum((r+c)%2 == stepmax%2 for r, c in vst)

def sol2(x):
    return (15066*x*x + 25546*x - 154023) // 17161

X = [65+2*i*131 for i in range(3)]
for x in X:
    print(x, sol(x), sol2(x))

print(sol2(26501365))