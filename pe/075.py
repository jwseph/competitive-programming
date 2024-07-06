from collections import Counter
from math import gcd

N = 1_500_000
S = set()
for a in range(1, N+1):
    b = 1
    while True:
        x, y, z = a**2-b**2, 2*a*b, a**2+b**2
        if x+y+z > N: break
        if 0 < min(x, y) and z < x+y:
            S.add((x+y+z) // gcd(x, y, z))
        b += 1

print(len(S))

cnt = Counter()
for p in S:
    cur = p
    while cur <= N:
        cnt[cur] += 1
        cur += p

print(list(cnt.values()).count(1))