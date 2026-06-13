
ones = [0] + [(i+1)*10**i for i in range(18)]

def g(d, w):  # solves d*10**w > 0
    if d == 1:
        return ones[w]+1
    return 10**w + d*ones[w]

def f(h):
    s = str(h)
    l = 0
    res = 0
    for i, c in enumerate(s):
        d = int(c)
        if d == 0: continue
        w = len(s)-i-1
        res += g(d, w)
        res += l*d*10**w if l else 0
        if d == 1: l += 1
    return res

n = int(input())

l = 0
r = 10**18
while l < r:
    h = (l+r+1)//2
    if f(h) > n: r = h-1
    else: l = h
print(l)