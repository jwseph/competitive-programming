from utils import *

A = readlines('14.in')

R = len(A)
C = len(A[0])
A = list(zip(*A))
res = 0
for row in A:
    row = list(row)
    i = 1
    for j, c in enumerate(row):
        if c == '.': continue
        if c == 'O':
            res += len(row)-i+1
            i += 1
        if c == '#':
            i = j+2
print(res)