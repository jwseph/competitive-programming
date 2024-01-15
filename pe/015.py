# (2n)!/(n!)^2

MOD = 344555666677777

def pow(n, p, mod=MOD):
    if p == 0: return 1
    if p%2 == 0: return pow(n*n % mod, p//2, mod)
    return n*pow(n, p-1, mod) % mod

N = 20

res = 1
for i in range(N+1, 2*N+1):
    res *= i
for i in range(1, N+1):
    res = res * pow(i, MOD-2) % MOD
print(res)