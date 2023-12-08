lines = open('aoc/day08.in').read().splitlines()

cmds = lines[0]
rest = lines[2:]
A = {}
for asdf in rest:
    key, val = asdf.split(' = ')
    val = val[1:-1]
    l, r = val.split(', ')
    A[key] = [l, r]

i = 0
cur = 'AAA'
while cur != 'ZZZ':
    cur = A[cur][0] if cmds[i%len(cmds)] == 'L' else A[cur][1]
    i += 1

print(i)