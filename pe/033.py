from fractions import Fraction
from math import prod

res = [
    f
    for a in range(10)
    for b in range(1, 10)
    for x in range(1, 10)
    for f in [Fraction(a*10+x, x*10+b), Fraction(x*10+a, b*10+x)]
    if f == Fraction(a, b) and 0 < f < 1
]

print(prod(res).denominator)