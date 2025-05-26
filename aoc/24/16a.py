from utils import *

a = lines = readlines('16.in')
n = len(a)
m = len(a[0])

q = [(0, n-2, 1, 0, 1)]
v = {}
while q:
    t, r, c, dx, dy  = heappop(q)
    # if t < 1000: print(f'{t=} {r=} {c=} {dx=} {dy=}')
    if a[r][c] == '#': continue
    if (r, c, dx, dy) in v: continue
    v[r, c, dx, dy] = t
    if a[r][c] == 'E':
        print(t)
    for dx2, dy2 in [(dy, -dx), (-dy, dx)]:
        if (r, c, dx2, dy2) in v: continue
        heappush(q, (t+1000, r, c, dx2, dy2))
    if (r+dx, c+dy, dx, dy) in v: continue
    heappush(q, (t+1, r+dx, c+dy, dx, dy))
print()
print(v[n-2, 1, 0, 1])