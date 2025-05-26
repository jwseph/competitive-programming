from utils import *

a = readlines('04.in')
n = len(a)
m = len(a[0])

res = 0
for r in range(n):
    for c in range(m):
        for dr, dc in d8:
            if all(0 <= x < n and 0 <= y < m and a[x][y] == 'XMAS'[i] for i in range(4) for (x, y) in [(r+i*dr, c+i*dc)]):
                res += 1
print(res)