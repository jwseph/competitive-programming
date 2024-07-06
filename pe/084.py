N = 40
K = 4

jump = [0]*N
r = range(1, K+1)
for A in [[(a, b), (c, d), (e, f)] for a in r for b in r for c in r for d in r for e in r for f in r]:
    cur = 0
    for x, y in A:
        cur += x+y
        if x != y: break
    else: continue
    jump[cur%40] += 1
for i in range(N):
    jump[i] /= K**6

go = 0
jail = N//4
skip = [[i] for i in range(N)]
for i in [2, 17, 33]:  # community chest
    skip[i] = 14*[i] + [go, jail]
for i in [7, 22, 36]:  # chance
    dr = du = N
    for r in [5, 15, 25, 35]: dr = min(dr, (r-i)%N)
    for u in [12, 28]: du = min(du, (u-i)%N)
    skip[i] = 6*[i] + [go, jail, 11, 24, 39, 5, i+dr, i+dr, i+du, i-3]
for i in range(N):
    skip[i] = [j%N for j in skip[i]]
skip[30] = [jail]  # go to jail

def land(i, p, j=-1):
    if skip[i] == [i] or i == j:
        P[i] += p
        return
    for j in skip[i]:
        land(j, p/len(skip[i]), i)

def fill(i, p):
    P[jail] += p * K**-3
    for di in range(N):
        j = (i+di)%N
        land(j, p*jump[di])

P = [0]*N
P[0] = 1
res = [0]*N
for _ in range(1000):
    for i in range(N):
        p = P[i]
        res[i] += p
        P[i] = 0
        fill(i, p)
tot = sum(res)
for i in range(N):
    res[i] /= tot
best = sorted(range(N), key=res.__getitem__, reverse=True)
print(best[:3])