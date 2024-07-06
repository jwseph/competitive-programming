from collections import defaultdict
from math import inf

D = [1452, 70, 20, 9, 6, 4, 3, 3, 2, 2, 2, 2, 2]
D = [2000, 100, 30, 20, 10, 10, 7, 7, 3, 3, 3, 3, 2, 2]
A = defaultdict(lambda: inf)
N = 12000

def sol(i, n=0, p=1, s=0, m=inf):
    if i > len(D) or p > N*1.2*10: return
    if n and p >= s:
        k = p-s + n
        if 2 <= k <= N: A[k] = min(A[k], p)
    if i == len(D): return
    for d in range(1, min(D[i], m+1)):
        sol(i+1, n+1, p*d, s+d, d)

sol(0)
print(sum(set(A.values())))