from utils import *

seeds, rest = read('05.in').split('\n\n', 1)
seeds = seeds.removeprefix('seeds: ').split(' ')
seeds = list(map(int, seeds))
A = list(seeds)
B = A[:]

for line in rest.split('\n'):
    if '-' in line or not line:
        A = B
        B = A.copy()
        continue
    a, b, c = list(map(int, line.split(' ')))
    print('- ', a, b, c)
    for i in range(len(A)):
        if i == 1: print(b, b+c)
        if b <= A[i] < b+c:
            if i == 1: print(A[i])
            B[i] = A[i] - (b-a)
            if (i == 1): print(B[i])

A = B
print(A)
print(min(A))