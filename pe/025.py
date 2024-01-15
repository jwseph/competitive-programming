from math import log10

def logfib(n):
    sq5 = 5**.5
    phi = (1+sq5)/2
    return n*log10(phi)-log10(sq5)

K = 999
l, r = 0, 10**9
while l < r:
    h = (l+r)//2
    if logfib(h) >= K: r = h
    else: l = h+1
print(l)