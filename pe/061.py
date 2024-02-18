from utils import sqrt

def check(n, t):
    if t == 0: res = (-1+sqrt(1+8*n))/2
    if t == 1: res = sqrt(n)
    if t == 2: res = (1+sqrt(1+24*n))/6
    if t == 3: res = (1+sqrt(1+8*n))/4
    if t == 4: res = (3+sqrt(9+40*n))/10
    if t == 5: res = (2+sqrt(4+12*n))/6
    return res == int(res) and res >= 1

def zero(n):
    return n//1000 and n%100//10

def sol(cur, v):
    if not cur:
        res = []
        for n in range(10**4):
            if not zero(n): continue
            for t in range(6):
                if v&1<<t or not check(n, t): continue
                res = max(res, sol(cur+[n], v|1<<t))
        return res
    if len(cur) == 5:
        n = cur[-1]%100*100+cur[0]//100
        if not zero(n): return
        for t in range(6):
            if v&1<<t or not check(n, t): continue
            return cur+[n]
        return []
    res = []
    for s in range(10**2):
        n = cur[-1]%100*100+s
        if not zero(n): continue
        for t in range(6):
            if v&1<<t or not check(n, t): continue
            res = max(res, sol(cur+[n], v|1<<t))
    return res

res = sol([], 0)
print(res, sum(res))