from utils import *

lines = open('aoc/day24.in').read().splitlines()

arr = []
for line in lines:
    left, right = line.split(' @ ')
    px, py, pz = list(map(int, left.split(', ')))
    vx, vy, vz = list(map(int, right.split(', ')))
    arr.append((px, py, pz, vx, vy, vz))

V = set()

def sol(x1, y1, z1, v1x, v1y, v1z, x2, y2, z2, v2x, v2y, v2z):
    A = [[v1y, -v1x, v1y*x1-v1x*y1], [v2y, -v2x, v2y*x2-v2x*y2]]
    A = rref(A)
    if A[0][:2] != [1, 0] or A[1][:2] != [0, 1]: return inf, inf
    x, y = A[0][-1], A[1][-1]
    if v1x and (x-x1)/v1x < 0 or v2x and (x-x2)/v2x < 0: return inf, inf
    if v1y and (y-y1)/v1y < 0 or v2y and (y-y2)/v2y < 0: return inf, inf
    return x, y

low = 200000000000000
up = 400000000000000
res = 0
for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        x, y = sol(*arr[i], *arr[j])
        if low <= x <= up and low <= y <= up:
            # print(x, y)
            # print(*arr[i], ' ', *arr[j])
            res += 1

print(res)