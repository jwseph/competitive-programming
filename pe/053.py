from utils import cache

@cache
def dp(n, k):
    if n == 0 or k == 0 or k == n: return 1
    return dp(n-1, k) + dp(n-1, k-1)

res = sum(dp(n, k) > 10**6 for n in range(101) for k in range(n+1))
print(res)