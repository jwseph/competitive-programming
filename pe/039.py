from functools import cache

@cache
def calc(p):
    res = 0
    for a in range(1, p//4+1):
        for b in range((p-a)//2+1):
            if a*a+b*b == (p-a-b)**2:
                res += 1
    return res

res = max(range(1001), key=calc)
print(res)