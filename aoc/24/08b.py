from utils import *

a = readlines('08.in')
n = len(a)
m = len(a[0])

d = defaultdict(list)
for r in range(n):
    for c in range(m):
        if a[r][c] == '.': continue
        d[a[r][c]].append(r+c*1j)

vst = set()
for ch, v in d.items():
    for x in v:
        for y in v:
            if x == y: continue
            z = y
            while 0 <= z.real < n and 0 <= z.imag < m:
                vst.add(z)
                z += y-x

print(len(vst))