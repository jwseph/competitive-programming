from utils import *

lines = readlines('02.in')

def inc(a):
    return all(x < y for x, y in pairwise(a))

def ok(a):
    return (inc(a) or inc(a[::-1])) and all(1 <= abs(x-y) <= 3 for x, y in pairwise(a))

res = 0
for s in lines:
    a = list(map(int, s.split()))
    cur = any(ok(a[:i] + a[i+1:]) for i in range(len(a)))
    res += cur
print(res)

