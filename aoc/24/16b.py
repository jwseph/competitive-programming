from utils import *

a = lines = readlines('16.in')
n = len(a)
m = len(a[0])

q = [(0, n-2, 1, 0, 1, ())]
v = {}
inputs = defaultdict(list)
while q:
    t, r, c, dx, dy, par  = heappop(q)
    # if t < 1000: print(f'{t=} {r=} {c=} {dx=} {dy=}')
    if a[r][c] == '#': continue
    if (r, c, dx, dy) in v:
        if t == v[r, c, dx, dy] and par: inputs[r, c, dx, dy].append(par)
        continue
    v[r, c, dx, dy] = t
    if par: inputs[r, c, dx, dy].append(par)
    if a[r][c] == 'E':
        print(t)
    for dx2, dy2 in [(dy, -dx), (-dy, dx)]:
        if (r, c, dx2, dy2) in v: continue
        heappush(q, (t+1000, r, c, dx2, dy2, (r, c, dx, dy)))
    if (r+dx, c+dy, dx, dy) in v: continue
    heappush(q, (t+1, r+dx, c+dy, dx, dy, (r, c, dx, dy)))

vv = set()
res = set()
def dfs(i):
    if i in vv: return
    vv.add(i)
    res.add(i[:2])
    for j in inputs[i]:
        dfs(j)

for i in v:
    # print(i[:2])
    if i[:2] == (1, m-2) and v[i] == 99460:
        dfs(i)


print()
print(len(res))