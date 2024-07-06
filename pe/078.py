N = 10**5
MOD = 10**6

dp = [0]*(N+1)
dp[0] = 1
for i in range(1, N+1):
    k = 0
    while i-k*(3*k-1)//2 >= 0:
        dp[i] += (-1 if (k+1)&1 else 1) * dp[i-k*(3*k-1)//2]
        dp[i] %= MOD
        k = -k+1 if k <= 0 else -k
    if dp[i] == 0:
        print(i)
        break