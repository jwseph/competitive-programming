from utils import *
from queue import PriorityQueue

A = open('aoc/day17.in').read().splitlines()
R = len(A)
C = len(A[0])

V = set()

def add(w, r, c, dr, dc):
    if r < 0 or r >= R or c < 0 or c >= C: return
    if (r, c, dr, dc) in V: return
    Q.put((w, r, c, dr, dc))

Q = PriorityQueue()
Q.put((0, 0, 0, 1, 0))
Q.put((0, 0, 0, 0, 1))
res = 10**9
while not Q.empty():
    w, r, c, dr, dc = Q.get()
    if (r, c, dr, dc) in V: continue
    V.add((r, c, dr, dc))
    if (r, c) == (R-1, C-1):
        res = min(res, w)
    for i in range(1, 11):
        if r+dr*i < 0 or r+dr*i >= R or c+dc*i < 0 or c+dc*i >= C: break
        w += int(A[r+dr*i][c+dc*i])
        if i < 4: continue
        add(w, r+dr*i, c+dc*i, dc, dr)
        add(w, r+dr*i, c+dc*i, -dc, -dr)
print(res)