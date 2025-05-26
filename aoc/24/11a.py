from utils import *

a = list(map(int, readlines('11.in')[0].split()))
n = len(a)
print(a)

for _ in range(75):
    b = []
    for x in a:
        if x == 0:
            b.append(1)
            continue
        if len(str(x)) %2 == 0:
            s = str(x)
            b.append(int(s[:len(s)//2]))
            b.append(int(s[len(s)//2:]))
            continue
        b.append(x*2024)
    a = b

print(len(a))