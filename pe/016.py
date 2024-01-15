# O(n^2)
N = 1000
dp = [[0]*N for t in range(N+1)]
dp[0][0] = 1
for t in range(1, N+1):
    for i in range(N-1):
        dp[t][i] += 2*dp[t-1][i]
        dp[t][i+1] += dp[t][i]//10
        dp[t][i] %= 10

res = sum(dp[N])
print(res)
print(sum(map(int, str(1<<1000))))