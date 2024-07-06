from utils import cache, precompute

fac, _ = precompute(9)

@cache
def calc(n):
    res = 0
    while n:
        res += fac[n%10]
        n //= 10
    return res

def sol(n):
    V = set()
    while n not in V:
        V.add(n)
        n = calc(n)
    return len(V)

res = sum(sol(n) == 60 for n in range(0, 10**6))
print(res)