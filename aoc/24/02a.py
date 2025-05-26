from utils import *
from itertools import pairwise

lines = readlines('02.in')

def inc(a):
    return all(x < y for x, y in pairwise(a))
res = 0
for s in lines:
    a = list(map(int, s.split()))
    cur = (inc(a) or inc(a[::-1])) and all(1 <= abs(x-y) <= 3 for x, y in pairwise(a))
    res += cur
print(res)

