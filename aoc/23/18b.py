from utils import *

lines = readlines('18.in')

r = c = 0
P = [(r, c)]
res = 2
for line in lines:
    a, b, color = line.split()
    b = int(color[2:-2], base=16)
    a = color[-2]
    if a == '0': c += b
    if a == '2': c -= b
    if a == '3': r -= b
    if a == '1': r += b
    res += b
    P.append((r, c))

for i in range(len(P)):
    j = i-1
    res += P[i][0]*P[j][1] - P[i][1]*P[j][0]

print(res//2)