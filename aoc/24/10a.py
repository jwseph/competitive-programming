from utils import *

a = readlines('10.in')
n = len(a)
m = len(a[0])

adj = defaultdict(list)
for r in range(n):
    for c in range(m):
        for dr, dc in d4:
            i, j = r+dr, c+dc
            if 0 <= i < n and 0 <= j < m and ord(a[i][j]) == ord(a[r][c])+1:
                adj[r, c].append((i, j))

def dfs(r, c, cur):
    if a[r][c] == '9':
        cur.add((r, c))
        return
    for i, j in adj[r, c]:
        dfs(i, j, cur)

res = 0
for r in range(n):
    for c in range(m):
        if a[r][c] == '0':
            cur = set()
            dfs(r, c, cur)
            res += len(cur)
print(res)