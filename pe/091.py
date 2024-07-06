from math import gcd

def sol(n):
    res = 3*n**2
    for r in range(1, n+1):
        for c in range(1, n+1):
            dr, dc = c//gcd(r, c), r//gcd(r, c)
            res += min((n-c)//dc, r//dr)
            res += min((n-r)//dr, c//dc)
    return res

print(sol(50))