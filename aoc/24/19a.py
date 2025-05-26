from utils import *

l1, l2 = grouplines(readlines('19.in'))
a = set(l1[0].split(', '))

@cache
def sol(s):
    if s in a:
        return True
    for i in range(1, len(s)):
        if sol(s[:i]) and sol(s[i:]):
            return True
    return False

res = 0
for s in l2:
    res += sol(s)
print(res)