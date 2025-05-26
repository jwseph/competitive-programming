from utils import *

lines = readlines('05.in')
h = lines.index('')
L, R = lines[:h], lines[h+1:]

out = defaultdict(list)
ind = Counter()

sat = []
for s in L:
    i = int(s[:2])
    j = int(s[3:])
    sat.append((i, j))

res = 0
for s in R:
    cur = list(map(int, s.split(',')))
    idx = invert(cur)
    print(cur)
    for l, r in sat:
        if l in idx and r in idx:
            if idx[l] >= idx[r]: print('bad', l, r)
    if all(idx[l] < idx[r] for l, r in sat if l in idx and r in idx):
        print('yay')
        res += cur[len(cur)//2]
print(res)