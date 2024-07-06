from decimal import Decimal, getcontext
from math import isqrt

getcontext().prec = 110

def sol(n):
    s = str(Decimal(n).sqrt()).replace('.', '')[:100]
    return sum(map(int, s))

res = 0
for n in range(1, 101):
    if isqrt(n)**2 == n: continue
    res += sol(n)
print(res)