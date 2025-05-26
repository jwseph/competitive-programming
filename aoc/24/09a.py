from utils import *

s = readlines('09.in')[0]
print(len(s))

a = []
for i, c in enumerate(s):
    for _ in range(int(c)):
        a.append(i//2 if i%2 == 0 else -1)

j = len(a)-1
for i in range(len(a)):
    while j > i and a[j] == -1:
        j -= 1
    if j <= i or a[i] != -1: continue
    a[i], a[j] = a[j], a[i]
    j -= 1

res = 0
for i in range(len(a)):
    if a[i] < 0: continue
    res += i*a[i]
print(res)