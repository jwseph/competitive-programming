from fractions import Fraction

N = 10**6

res = Fraction(0, 1)
for d in range(1, N+1):
    n = int((d*3-1)/7)
    f = Fraction(n, d)
    if f.numerator != n: continue
    res = max(res, f)
print(res)