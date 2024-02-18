from collections import defaultdict
from math import inf

A = defaultdict(list)
N = 10**5
for i in range(N):
    c = i**3
    A[tuple(sorted(map(int, str(c))))].append(c)

res = inf
for C in A.values():
    if len(C) == 5:
        res = min(res, *C)
print(res)