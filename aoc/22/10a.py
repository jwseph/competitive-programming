from utils import *

lines = readlines('10.in')
print(lines)
q = []
t = 0
x = 0
res = 0
for line in lines:
    a, *b = line.split()
    while q and q[0][0] == t:
        _, dx = heappop(q)
        x += dx
    if t+1 in [20, 60, 100, 140, 180, 220]:
        res += (t+1)*x
    if a == 'addx':
        q.append((t+2, int(b[0])))
    t += 1
print(res)