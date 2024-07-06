from utils import Primes

N = 10**6
P = Primes(N)

print(sum(P.phi[2:]))