from utils import quadratic

p, q = quadratic(3, -8, 4-64)

N = 10**9
res = 0
for i in range(1, 10**6):
    y = i*i
    for b in [-8, 8]:
        for p in quadratic(3, b, 4-y):
            # if not isinstance(p, int): continue
            if isinstance(p, complex): continue
            cur = i*p
            if i*p%4: continue
            if not (i*p).is_integer(): continue
            print(i*p)
            per = p*3
            if per.is_integer() and 0 <= per <= N:
                # if b == -8: print(p)
                # res += abs(p)*3
                res += per
# for i in range(1, 100):
#     y = -i*i
#     if y%16: continue
#     for p in quadratic(3, -8, 4-y):
#         p = -p
#         print(p)
#         if not isinstance(p, int): continue
#         if 1 <= p <= N:
#             print(p)
#             res += p*3
print(res)