from utils import *

l1, l2 = grouplines(readlines('19.in'))
a = set(l1[0].split(', '))

@cache
def sol(s):
    if s == '':
        return 1
    res = 0
    for i in range(1, len(s)+1):
        if s[:i] in a:
            res += sol(s[i:])
    return res

res = 0
for s in l2:
    res += sol(s)
print(res)