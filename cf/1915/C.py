NT = int(input())
from math import sqrt
for _ in range(NT):
    N = int(input())
    A = list(map(int, input().split()))
    tot = sum(A)
    sqt = round(sqrt(tot))
    if sqt*sqt == tot:
        print('YES')
    else: print('NO')