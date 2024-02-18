from utils import sieve

N = 10**6
P = sieve(N)
A = [i for i in range(N) if P[i]]

def sol(p, res):
    cur = 0
    l = r = 0
    while r < len(A) and A[r] <= p and cur <= p:
        cur += A[r]
        r += 1
        while r-l > res and cur > p:
            cur -= A[l]
            l += 1
        if cur == p: res = max(res, r-l)
    return res

res = 0
q = -1
for p in A[::-1]:
    print(f'\r{q} ({res} terms)', end='')
    cur = sol(p, res)
    if res < cur:
        res = cur
        q = p