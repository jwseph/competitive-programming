from utils import cache

@cache
def sol(n):
    if n == 1: return 0
    if n == 89: return 1
    return sol(sum(i**2 for i in map(int, str(n))))

res = 0
for i in range(1, 10**7):
    res += sol(i)
print(res)