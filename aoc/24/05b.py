from utils import *

lines = readlines('05.in')
h = lines.index('')
L, R = lines[:h], lines[h+1:]

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
    adj = defaultdict(list)
    cnt = Counter()
    v = set()
    for l, r in sat:
        if l in idx and r in idx:
            if idx[l] >= idx[r]: print('bad', l, r)
            adj[l].append(r)
            cnt[r] += 1
            v |= {l, r}
    if all(idx[l] < idx[r] for l, r in sat if l in idx and r in idx):
        continue
    
    q = deque()
    for i in v:
        if cnt[i] == 0: 
            q.append(i)
    x = []
    while q:
        i = q.popleft()
        x.append(i)
        for j in adj[i]:
            cnt[j] -= 1
            if cnt[j] == 0:
                q.append(j)
    print(x)
    assert len(x) == len(cur)
    res += x[len(x)//2]
        
print(res)











