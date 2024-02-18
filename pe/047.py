from functools import cache
from math import sqrt

@cache
def factor(num):
    if num == 1: return []
    for i in range(2, int(sqrt(num))+1):
        if num%i == 0:
            return [i]+factor(num//i)
    return [num]

def calc(x):
    return len(set(factor(x))) == 4

x = 2
cur = 0
while cur < 4:
    cur += 1
    if not calc(x): cur = 0
    x += 1
print(x-4)