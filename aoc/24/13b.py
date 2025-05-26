from utils import *

lines = readlines('13.in')

def sol(x, y, d1x, d1y, d2x, d2y):
    a = rref([
        [d1x, d2x, x],
        [d1y, d2y, y],
    ])
    d1 = a[0][-1]
    d2 = a[1][-1]
    if d1%1 == d2%1 == 0: return d1*3+d2
    return inf

res = 0
for l1, l2, l3 in grouplines(lines):
    x, y = getnums(l3)
    cur = sol(x+10000000000000, y+10000000000000, *getnums(l1), *getnums(l2))
    if cur < inf:
        res += cur
print(res)