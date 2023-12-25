from utils import *

lines = readlines('24.in')

arr = []
for line in lines:
    left, right = line.split(' @ ')
    px, py, pz = list(map(int, left.split(', ')))
    vx, vy, vz = list(map(int, right.split(', ')))
    arr.append((px, py, pz, vx, vy, vz))

order = ['x', 'y', 'z', 'a', 'b', 'c'] + [i+j for i in 'xyz' for j in 'abc']
idx = {v: i for i, v in enumerate(order)}

def sol3(x1, y1, z1, a1, b1, c1):
    # (x-x1)/(a-a1)=(y-y1)/(b-b1)=(z-z1)/(c-c1)
    # (x-x1)(b-b1)=(y-y1)(a-a1)
    # xb-x1b-xb1-ya+y1a+ya1=y1a1-x1b1
    # xc-x1c-xc1-za+z1a+za1=z1a1-x1c1
    # yc-y1c-yc1-zb+z1b+zb1=z1b1-y1c1
    eqs = [
        {'xb': 1, 'b': -x1, 'x': -b1, 'ya': -1, 'a': y1, 'y': a1, 'ans': y1*a1-x1*b1},
        {'xc': 1, 'c': -x1, 'x': -c1, 'za': -1, 'a': z1, 'z': a1, 'ans': z1*a1-x1*c1},
        {'yc': 1, 'c': -y1, 'y': -c1, 'zb': -1, 'b': z1, 'z': b1, 'ans': z1*b1-y1*c1},
    ]
    return [[eq.get(v, 0) for v in order] + [eq['ans']] for eq in eqs]

X = []
for i in range(5):
    for row in sol3(*arr[i]):
        X.append(row)

X = rref(X)
res = X[0][-1]+X[1][-1]+X[2][-1]
print(res)