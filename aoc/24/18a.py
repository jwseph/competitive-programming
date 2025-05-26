from utils import *

a = lines = readlines('18.in')

n = m = 71

q = deque()
v = set()

for i, line in enumerate(lines):
    if i < 1024:
        r, c = getnums(lines[i])
        v.add((r, c))

q.append((0, 0, 0))
v.add((0, 0))
while q:
    t, r, c = q.popleft()
    if (r, c) == (n-1, m-1):
        print(t)
        break
    for i, j in d4a(r, c, n, m, v):
        q.append((t+1, i, j))