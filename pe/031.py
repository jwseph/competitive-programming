from functools import cache

A = [1, 2, 5, 10, 20, 50, 100, 200]

@cache
def sol(x, i):
    if x < 0: return 0
    if i == len(A): return x == 0
    return sol(x-A[i], i) + sol(x, i+1)

res = sol(200, 0)
print(res)