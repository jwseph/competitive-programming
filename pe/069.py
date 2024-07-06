from utils import Primes

N = 10**6
P = Primes(N)
res = max(range(2, N+1), key=lambda n: n/P.phi[n])
print(res)