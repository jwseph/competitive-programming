from math import prod

def sol(i):
    i -= 1
    w = 9
    s = 1
    while i >= s*w:
        i -= s*w
        s += 1
        w *= 10
    p = i%s
    n = w//10+1+i//s
    return int(str(n)[p])

res = prod(sol(10**p) for p in range(7))
print(res)