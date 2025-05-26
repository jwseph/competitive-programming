from utils import *

lines = readlines('01.in')

a = []
b = []

for s in lines:
    x, y = map(int, s.split())
    a.append(x)
    b.append(y)

a.sort()
b.sort()
cnt = Counter(b)
print(sum(cnt[x]*x for x in a))