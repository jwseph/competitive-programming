from sympy import isprime
from functools import cache
from utils import bisect_right

N = 10**4
P = list(filter(isprime, range(N)))

def check(a, b):
    return isprime(int(f'{a}{b}'))

@cache
def sol(n):
    if n == 0: return [set()]
    res = []
    for group in sol(n-1):
        for p in P[bisect_right(P, max(group, default=-1)):]:
            if all(check(a, p) and check(p, a) for a in group):
                res.append(group|{p})
    return res

print(sum({13, 5197, 5701, 8389, 6733}))
print(sol(5), sum(sol(5)[0]))