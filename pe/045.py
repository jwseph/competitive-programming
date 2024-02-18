from math import isqrt

i = 1
while True:
    h = i*(2*i-1)
    d = 24*h+1
    q = isqrt(d)
    if q*q == d and q%6 == 5:
        print(h)
    i += 1