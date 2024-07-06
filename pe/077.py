from utils import Primes

N = 10**3
P = Primes(N).primes
dp = [0]*(N+1)

dp[0] = 1
for p in P:
    for i in range(p, N+1):
        dp[i] += dp[i-p]

for i in range(N+1):
    if dp[i] > 5000:
        print(i)
        break