from math import isqrt

def expand(n):
    A = [isqrt(n)]
    if isqrt(n)**2 == n: return A
    V = set()
    a = 1
    b = -isqrt(n)
    while (a, b) not in V:
        V.add((a, b))
        t = int(a/(n**.5+b))
        A.append(t)
        a = (n-b**2)//a
        b = -b - a*t
    return A

res = sum(len(expand(n))%2 == 0 for n in range(10**4+1))
print(res)