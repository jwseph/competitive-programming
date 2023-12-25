from utils import *

A = readlines('17.in')

R = len(A)
C = len(A[0])

V = set()

def add(w, r, c, dr, dc):
    if r < 0 or r >= R or c < 0 or c >= C: return
    if (r, c, dr, dc) in V: return
    heappush(Q, (w, r, c, dr, dc))

Q = []
heappush(Q, (0, 0, 0, 1, 0))
heappush(Q, (0, 0, 0, 0, 1))
res = 10**9
while Q:
    w, r, c, dr, dc = heappop(Q)
    if (r, c, dr, dc) in V: continue
    V.add((r, c, dr, dc))
    if (r, c) == (R-1, C-1):
        res = min(res, w)
    for i in range(1, 4):
        if r+dr*i < 0 or r+dr*i >= R or c+dc*i < 0 or c+dc*i >= C: break
        w += int(A[r+dr*i][c+dc*i])
        add(w, r+dr*i, c+dc*i, dc, dr)
        add(w, r+dr*i, c+dc*i, -dc, -dr)
print(res)