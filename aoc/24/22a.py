from utils import *

a = readlines('22.in')

def f(x, n=1):
    if n == 0: return x

    x ^= x*64
    x %= 16777216

    x ^= x//32
    x %= 16777216

    x ^= x*2048
    x %= 16777216
    
    return f(x, n-1)

res = 0
for s in a:
    res += f(int(s), 2000)
print(res)

