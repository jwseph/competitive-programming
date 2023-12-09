lines = open('aoc/day08.in').read().splitlines()

from math import lcm

cmds = lines[0]
rest = lines[2:]
A = {}
for asdf in rest:
    key, val = asdf.split(' = ')
    val = val[1:-1]
    l, r = val.split(', ')
    A[key] = [l, r]

i = 0
curs = [list(A.keys())[i] for i in range(len(A)) if list(A.keys())[i][2] == 'A']

res = 1
for cur in curs:
    i = 0
    while not cur.endswith('Z'):
        cur = A[cur][0] if cmds[i%len(cmds)] == 'L' else A[cur][1]
        i += 1
    # works because len(cmds) and cycle lengths are prime
    res = lcm(res, i)

print(res)