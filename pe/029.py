from functools import cache
from collections import Counter

@cache
def factor(n):
    if n == 1: return []
    for i in range(2, int(n**.5)+1):
        if n%i == 0:
            return [i]+factor(n//i)
    return [n]

V = set()
for a in range(2, 101):
    cur = Counter()
    add = Counter(factor(a))
    cur += add
    for b in range(2, 101):
        cur += add
        V.add(tuple(sorted(cur.items())))

print(len(V))