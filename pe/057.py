from utils import Fraction

N = 10**3
cur = Fraction(0)
res = 0
for _ in range(N):
    cur = Fraction(1, 2+cur)
    f = 1+cur
    res += len(str(f.numerator)) > len(str(f.denominator))
print(res)