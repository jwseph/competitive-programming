from utils import *

a = readlines('12.in')
n = len(a)
m = len(a[0])

v = set()

perm = []
area = []

def dfs(r, c, cur):
    if (r, c) in v and a[r][c] == cur: return
    if r < 0 or r >= n or c < 0 or c >= m or a[r][c] != cur:
        perm[-1] += 1
        return
    v.add((r, c))
    area[-1] += 1
    for dr, dc in d4:
        i, j = r+dr, c+dc
        dfs(i, j, cur)

res = 0
for r in range(n):
    for c in range(m):
        if (r, c) in v: continue
        area.append(0)
        perm.append(0)
        dfs(r, c, a[r][c])
        res += area[-1]*perm[-1]
        print(f'{a[r][c]}, {area[-1]} {perm[-1]}')
print(res)