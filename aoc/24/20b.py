from utils import *

a = (readlines('20.in'))
a = [list(row) for row in a]

n = len(a)
m = len(a[0])

q = deque()
v = {}
for r in range(n):
    for c in range(m):
        if a[r][c] == 'S':
            q.append((0, r, c))
            v[r, c] = 0
            sr, sc = r, c
while q:
    t, r, c = q.popleft()
    if a[r][c] == 'E':
        print(t)
    for dr, dc in d4:
        i, j = r+dr, c+dc
        if 0 <= i < n and 0<=j<m and a[i][j] != '#' and (i, j) not in v:
            q.append((t+1, i, j))
            v[i, j] = t+1


q = deque()
v2 = {}
for r in range(n):
    for c in range(m):
        if a[r][c] == 'E':
            q.append((0, r, c))
            v2[r, c] = 0
            er, ec = r, c
while q:
    t, r, c = q.popleft()
    if a[r][c] == 'E':
        print(t)
    for dr, dc in d4:
        i, j = r+dr, c+dc
        if 0 <= i < n and 0<=j<m and a[i][j] != '#' and (i, j) not in v2:
            q.append((t+1, i, j))
            v2[i, j] = t+1
print(v[er, ec])
print(v2[sr, sc])
res=0
save = []
for r in range(n):
    for c in range(m):
        if a[r][c] == '#': continue
        print(f'{v[r,c]+v2[r,c]=}')
        for dr in range(-20, 21):
            for dc in range(abs(dr)-20, 21-abs(dr)):
                i, j = r+dr, c+dc
                if 0 <= i < n and 0<=j<m and a[i][j] != '#':
                    save.append((v[er, ec] - (v[r, c] + v2[i, j] + abs(dr)+abs(dc))))
# print(sorted(save)[::-1])
for s in save:
    res += s >= 100
print(res)