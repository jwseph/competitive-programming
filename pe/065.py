from utils import CF

f = CF.approx((i+1)//3*2 if i%3 == 2 else 1 if i else 2 for i in range(100))
res = sum(map(int, str(f.numerator)))
print(res)