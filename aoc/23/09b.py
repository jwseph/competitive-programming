from utils import *

lines = readlines('09.in')

res = 0

for line in lines:
    A = [list(map(int, line.split()))]
    A[0] = A[0][::-1]
    while not all(num == 0 for num in A[-1]):
        A.append([b-a for a, b in zip(A[-1], A[-1][1:])])
    A[-1].append(0)
    for r in range(len(A)-1)[::-1]:
        A[r].append(A[r][-1] + A[r+1][-1])
    print(A[0][-1])
    res += A[0][-1]

print(res)