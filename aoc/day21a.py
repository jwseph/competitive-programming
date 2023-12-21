from utils import *

A = open('aoc/day21.in').read().splitlines()
R = len(A)
C = len(A[0])

from collections import deque
q = deque()

for r in range(R):
    for c in range(C):
        if A[r][c] == 'S':
            q.append((r, c))
print(q)
steps = 0
while len(q):
    vst = set()
    for _ in range(len(q)):
        r, c = q.popleft()
        adj = ((r-1, c), (r, c-1), (r+1, c), (r, c+1))
        for i, j in adj:
            if i < 0 or i >= R or j < 0 or j >= C: continue
            if (i, j) in vst: continue
            if A[i][j] == '#': continue
            vst.add((i, j))
            q.append((i, j))
    steps += 1
    if steps == 64: print(len(q))