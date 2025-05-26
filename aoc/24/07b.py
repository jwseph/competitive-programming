from utils import *

a = readlines('07.in')
n = len(a)
m = len(a[0])

def sol(x):
    res = [x[0]]
    for v in x[1:]:
        res = [p for u in res for p in [u*v, u+v, int(str(u)+str(v))]]
    return res

res = 0
for s in a:
    l, r = s.split(': ')
    res += (int(l) in sol(list(map(int, r.split())))) * int(l)
print(res)