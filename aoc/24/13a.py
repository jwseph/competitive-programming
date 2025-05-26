from utils import *

lines = readlines('13.in')

def sol(x, y, d1x, d1y, d2x, d2y):
    res = inf
    for d1 in range(105):
        for d2 in range(105):
            if x == d1*d1x+d2*d2x and y == d1*d1y+d2*d2y:
                res = min(res, d1*3+d2)
    return res

res = 0
for l1, l2, l3 in grouplines(lines):
    cur = sol(*getnums(l3), *getnums(l1), *getnums(l2))
    if cur < inf:
        res += cur
print(res)