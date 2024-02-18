from sympy import isprime

from itertools import permutations

res = 0

for n in range(1, 10):
    for a in map(int, map(''.join, permutations(''.join(map(str, range(1, n+1)))))):
        if isprime(a):
            res = max(res, a)

print(res)