from utils import *

a, moves = grouplines(readlines('15.in'))
moves = ''.join(moves)

n = len(a)
m = len(a[0])

for r in range(n):
    a[r] = list(a[r])
    for c in range(m):
        if a[r][c] == '@':
            rr, rc = r, c

for move in moves:
    dr, dc = d4['>^<v'.index(move)]
    nr, nc = rr, rc
    pos = [(rr, rc)]
    nr += dr
    nc += dc
    pos.append((nr, nc))
    while a[nr][nc] == 'O':
        nr += dr
        nc += dc
        pos.append((nr, nc))
    if a[nr][nc] == '#':continue
    
    for (r1, c1), (r2, c2) in pairwise(pos[::-1]):
        a[r1][c1] = a[r2][c2]
    a[rr][rc] = '.'
    rr += dr
    rc += dc

res = 0
for r in range(n):
    for c in range(m):
        if a[r][c] != 'O': continue
        res += 100*r+c
print(res)

print('\n'.join(map(''.join, a)))