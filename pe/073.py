from utils import Primes

N = 12000
P = Primes(N)

def sol(d):
    l = d//3 + 1
    r = (d-1)//2
    return P.phi2(r, d) - P.phi2(l-1, d)

res = sum(map(sol, range(2, N+1)))
print(res)