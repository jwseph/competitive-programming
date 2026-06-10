from utils import *

lines = readlines('11.in')

a = defaultdict(list)
for line in lines:
    i, right = line.split(': ')
    for j in right.split():
        a[i].append(j)

@cache
def sol(i):
    if i == 'out': return 1
    res = 0
    for j in a[i]:
        res += sol(j)
    return res

print(sol('you'))