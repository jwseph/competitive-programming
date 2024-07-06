from utils import Primes

P = Primes(10**7)

def sol(x):
    p = P.phi[x]
    return (x%2 == 0 or P[x] or sorted(str(p)) != sorted(str(x)), x/p)

res = min(range(2, 10**7), key=sol)
print(res)