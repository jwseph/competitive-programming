from utils import Primes

N = 5*10**7
P = Primes(2*10**6)

S = set()
for p in P.primes:
    for q in P.primes:
        cur = p**2 + q**3
        if cur >= N: break
        S.add(cur)

res = set()
for x in S:
    for r in P.primes:
        cur = x + r**4
        if cur >= N: break
        res.add(cur)
print(len(res))