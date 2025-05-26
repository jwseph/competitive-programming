from utils import *

a = readlines('22.in')

def f(x, n=1):
    if n == 0: return [x]

    x ^= x*64
    x %= 16777216

    x ^= x//32
    x %= 16777216

    x ^= x*2048
    x %= 16777216
    
    res = f(x, n-1)
    res.append(x)
    return res

# print(f(123, 8)[::-1])
res = 0
cnt = defaultdict(dict)
for i, x in enumerate(map(int, a)):
    dif = []
    p = x
    ok = 0
    while ok < 2000:
        x ^= x*64
        x %= 16777216
        x ^= x//32
        x %= 16777216
        x ^= x*2048
        x %= 16777216
        dif.append(x%10-p%10)
        if len(dif) >= 4:
            ok += 1
            cnt[tuple(dif[-4:])][i] = x%10
        p = x
# print(sum(cnt[-2,1,-1,3].values()))
print(max(sum(d.values()) for d in cnt.values()))
    
# res = 0
# for s in a:
#     cur = f(int(s), 2000)[::-1]
    
#     res += f(int(s), 2000)
# print(res)

