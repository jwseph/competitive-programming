from functools import cache
from math import prod
from collections import Counter

@cache
def factor(num):
    if num == 1: return []
    for i in range(2, int(num**.5)+1):
        if num%i == 0:
            return [i]+factor(num//i)
    return [num]

n = 1
while True:
    cnt = Counter(factor(n)) + Counter(factor(n+1))
    cnt[2] -= 1
    div = prod(v+1 for v in cnt.values())
    if div > 500:
        print(n*(n+1)//2)
        break
    n += 1