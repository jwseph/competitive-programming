from itertools import permutations, product
from random import randint
from fractions import Fraction

B = [
    '({a}{}{b}){}({c}{}{d})',
    '(({a}{}{b}){}{c}){}{d}',
    '({a}{}({b}{}{c})){}{d}',
    '{a}{}(({b}{}{c}){}{d})',
    '{a}{}({b}{}({c}{}{d}))',
]

def calc(exp, a, b, c, d) -> Fraction | None:
    try:
        return eval(exp.replace('{', 'Fraction({').replace('}', '})').format(a=a, b=b, c=c, d=d))
    except ZeroDivisionError:
        return None

D = {}
X = [randint(10**3, 10**4) for _ in range(4)]
for a, b, c, d in permutations(['{a}', '{b}', '{c}', '{d}']):
    for ops in product('+-*/', repeat=3):
        for exp in B:
            exp = exp.format(*ops, a=a, b=b, c=c, d=d)
            D.setdefault(calc(exp, *X), exp)
A = D.values()
print(len(A))

def sol(a, b, c, d):
    S = set()
    for exp in A:
        cur = calc(exp, a, b, c, d)
        if cur is None or cur.denominator != 1: continue
        S.add(cur.numerator)
    res = 0
    while res+1 in S: res += 1
    return (res, a*1000+b*100+c*10+d)

res = (0, 0)
for d in range(10):
    for c in range(d):
        for b in range(c):
            for a in range(b):
                res = max(res, sol(a, b, c, d))
print(res)