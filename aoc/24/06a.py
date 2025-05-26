from utils import *

a = readlines('06.in')
n = len(a)
m = len(a[0])

for r in range(n):
    a[r] = list(a[r])
    for c in range(m):
        if a[r][c] == '^':
            rr, rc = r, c
            dr, dc = -1, 0
            a[r][c] = '.'

r, c = rr, rc
v = set()
while 0 <= r < n and 0 <= c < m:
    v.add((r, c))
    if 0 <= r+dr < n and 0 <= c+dc < m and a[r+dr][c+dc] == '#': 
        dr, dc = dc, -dr
    r += dr
    c += dc

print(len(v))