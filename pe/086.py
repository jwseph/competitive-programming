from collections import defaultdict
from math import gcd
from utils import Primes

N = 10**5
S = defaultdict(set)
P = Primes(N)

for m in range(1, N):
    n = 1
    while 2*n*m <= N:
        a, b = sorted([m*m-n*n, 2*n*m])
        if a > 0 and b > 0:
            f = gcd(a, b)
            a //= f
            b //= f
            S[a].add(b)
            S[b].add(a)
        n += 1

def find(x):
    for f in P.factors(x):
        for y in S[x//f]:
            yield y*f

res = 0
c = 0
while res <= 10**6:
    c += 1
    for d in find(c):
        l = max(1, d-c)
        r = min(c, d//2)
        res += max(r-l+1, 0)
print(f'{res=}')
print(f'{c=}')