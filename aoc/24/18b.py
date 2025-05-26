from utils import *

a = lines = readlines('18.in')

n = 71
m = 71
a = [[False]*m for _ in range(n)]

for pos, line in enumerate(lines):
    r, c = getnums(lines[pos])
    a[r][c] = True

    q = deque()
    q.append((0, 0))
    v = set()
    v.add((0, 0))
    t = 0
    solvable = False
    while q:
        for _ in range(len(q)):
            r, c = q.popleft()
            if (r, c) == (n-1, m-1):
                q = []
                solvable = True
                break
            for dr, dc in d4:
                i, j = dr+r, c+dc
                if i < 0 or i >= n or j < 0 or j >= m: continue
                if (i, j) in v or a[i][j]: continue
                v.add((i, j))
                q.append((i, j))
        t += 1
    if not solvable:
        print(lines[pos])
        break