from functools import cache

@cache
def sol(n):
    if n == 1: return 1
    return 1 + (sol(n//2) if n%2 == 0 else sol(3*n+1))

res = max(range(1, 10**6), key=sol)
print(res)