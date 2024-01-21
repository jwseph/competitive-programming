# 0.202s

res = set()

def sol(x, u=set(range(1, 10))):
    if len(u) == 4:
        p = 10
        while x//p:
            a, b = x//p, x%p
            c = a*b
            s = str(c)
            if len(s) == len(u) and set(map(int, s)) == u:
                res.add(c)
            p *= 10
    for d in u:
        sol(x*10+d, u-{d})

sol(0)
print(sum(res))