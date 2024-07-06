from utils import quadratic

p, q = quadratic(3, -8, 4-64)

N = 10**9
res = 0
for i in range(1, N+1):
    y = i*i
    for a, b, c in [(3, 8, 4), (3, -2, -1)]:
        for x in quadratic(a, b, 4-y):
            if isinstance(x, complex): continue
            A = x*i/4
            P = 3*x+2 if b == 8 else 3*x+1
            sides = (x, x+1, x+1) if b == 8 else (x, x, x+1)
            if x.is_integer() and A.is_integer() and A and 0 <= P <= N:
                print(f'{A=} {P=} {sides=}')
                res += P
                print(res)
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