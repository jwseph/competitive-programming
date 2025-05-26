from utils import *

a = readlines('06.in')
n = len(a)
m = len(a[0])

print(n, m)

for r in range(n):
    a[r] = list(a[r])
    for c in range(m):
        if a[r][c] == '^':
            rr, rc = r, c
            dr, dc = -1, 0
            a[r][c] = '.'

def sol(r, c, dr, dc):
    v = set()
    while 0 <= r < n and 0 <= c < m:
        if (r, c, dr, dc) in v: return True
        v.add((r, c, dr, dc))
        while 0 <= r+dr < n and 0 <= c+dc < m and a[r+dr][c+dc] == '#': 
            dr, dc = dc, -dr
        r += dr
        c += dc
    return False

res = 0
for r in range(n):
    a[r] = list(a[r])
    for c in range(m):
        if a[r][c] == '.' and (r, c) != (rr, rc):
            a[r][c] = '#'
            if sol(rr, rc, dr, dc):
                res += 1
                # print(r, c)
                print(res)
            a[r][c] = '.'

print(res)