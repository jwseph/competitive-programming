from utils import *

a =(readlines('21.in'))

def sol(dr, dc, n):
    # presses to move by dr and dc and then click A
    if n == 0:
        return abs(dr)+abs(dc)+1
    res = 0
    if dr == 0 and dc == 0:
        res += 1
    if dr == 0 and dc < 0:
        res += sol(1,0,n-1) + sol(0,-2,n-1) + abs(dc) + sol(0,2,n-1) + sol(-1,0,n-1) + 1
    if dr == 0 and dc > 0:
        res += sol(1,0,n-1) + abs(dc) + sol(-1,0,n-1) + 1
    if dc == 0 and dr < 0:
        res += sol(0,-1,n-1) + abs(dr) + sol(0,1,n-1) + 1
    if dr == 0 and dc > 0:
        res += sol(1,0,n-1) + sol(0,-1,n-1) + abs(dr) + sol(0,1,n-1) + sol(-1,0,n-1) + 1
    if dr > 0 and dc < 0:
        res += sol(1,0,n-1) + sol(0,-1,n-1) + abs(dc) + sol(0,-1,n-1) + abs(dr) + sol(0,2,n-1) + sol(-1,0,n-1) + 1
    if dr < 0 and dc < 0:  # sus
        res += sol(0,-1,n-1) + abs(dr) + sol(1,0,n-1) + sol(0,-1,n-1) + abs(dc) + sol(0,2,n-1) + sol(-1,0,n-1) + 1
    if dr < 0 and dc > 0:
        res += sol(0,-1,n-1) + sol(0,1,n-1) + abs(dr) + sol(1,0,n-1) + sol(-1,0,n-1) + abs(dc) + 1
    if dr > 0 and dc > 0:
        res += sol(1,0,n-1) + sol(0,-1,n-1) + abs(dc) + abs(dr) + sol(0,1,n-1) + sol(-1,0,n-1) + 1
    return res

    # '<A'
    # 'v<<A>>^A'

key = '0123456789A'
row = [3, 2, 2, 2, 1, 1, 1, 0, 0, 0, 3]
col = [1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 2]

res = 0
for pat in a:
    cur = 0
    for c, d in pairwise('A'+pat):
        i = key.index(c)
        j = key.index(d)
        cur += sol(row[j]-row[i], col[j]-col[i], 0)
    print(cur)
    res += int(pat[:3])*cur
print(res)