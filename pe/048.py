MOD = 10**10

res = 0
for i in range(1, 1001):
    res += pow(i, i, MOD)
    res %= MOD
print(res)