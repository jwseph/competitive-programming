from utils import sieve, inf

P = sieve(10**6)

res = []

def gen(n, k, cur=''):
    if res: return
    if n == 0:
        if k: return
        sm = inf
        cnt = 0
        for d in range(10):
            if d == 0 and cur[0] == '*': continue
            p = int(cur.replace('*', str(d)))
            if not P[p]: continue
            sm = min(sm, p)
            cnt += 1
        if cnt == 8:
            res.append(sm)
        return
    for d in range(10):
        if cur or d:
            gen(n-1, k, f'{cur}{d}')
    if k:
        gen(n-1, k-1, cur+'*')

for n in range(1, 7):
    for k in range(1, n+1):
        gen(n, k)

print(res)