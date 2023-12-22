from utils import *

lines = open('aoc/day22.in').read().splitlines()

bricks = []
for line in lines:
    left, right = line.split('~')
    x1, y1, z1 = list(map(int, left.split(',')))
    x2, y2, z2 = list(map(int, right.split(',')))
    if x1 > x2: x1, x2 = x2, x1
    if z1 > z2: z1, z2 = z2, z1
    if y1 > y2: y1, y2 = y2, y1
    bricks.append((x1, y1, z1, x2, y2, z2))

from copy import deepcopy

def fall(arr, fidx=None):
    if fidx is None: fidx = set()
    arr = deepcopy(arr)
    res = 0
    vst = set()
    for (x1, y1, z1, x2, y2, z2) in arr:
        for x in range(x1, x2+1):
            for y in range(y1, y2+1):
                for z in range(z1, z2+1):
                    vst.add((x, y, z))

    for i, (x1, y1, z1, x2, y2, z2) in enumerate(arr):
        for x in range(x1, x2+1):
            for y in range(y1, y2+1):
                for z in range(z1, z2+1):
                    vst.remove((x, y, z))
        z1 -= 1
        z2 -= 1
        while not any(z < 0 or (x, y, z) in vst for x in range(x1, x2+1) for y in range(y1, y2+1) for z in range(z1, z2+1)):
            z1 -= 1
            z2 -= 1
            res += 1
            # print('fall')
            fidx.add(i)
        z1 += 1
        z2 += 1
        for x in range(x1, x2+1):
            for y in range(y1, y2+1):
                for z in range(z1, z2+1):
                    vst.add((x, y, z))
        arr[i] = (x1, y1, z1, x2, y2, z2)
    return arr, res, fidx

def fall2(arr):
    arr = deepcopy(arr)
    fidx = set()
    arr, fell, fidx = fall(arr, fidx)
    while fell:
        arr, fell, fidx = fall(arr, fidx)
    return arr, len(fidx)

res = 0
print(bricks)
bricks, fs = fall2(bricks)
print(bricks)
# exit()
for i in range(len(bricks)):
    tmp = bricks[:i]+bricks[i+1:]
    _, fs = fall2(tmp)
    res += fs
    print('changed', fs)
print(res)