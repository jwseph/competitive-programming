'''
Speed improvements: reading stack from input efficiently
'''

lines = open('aoc/22/05.in').read().splitlines()
n = 9
ar = [[] for _ in range(9)]
moves = False
for line in lines:
    if line.startswith(' 1'):
        moves = True
        for i in range(9):
            ar[i].reverse()
        continue
    if not line: continue
    if moves:
        _, n, _, src, _, dst = line.split()
        n, src, dst = map(int, [n, src, dst])
        src -= 1
        dst -= 1
        tmp = []
        for _ in range(n):
            tmp.append(ar[src].pop())
        for _ in range(n):
            ar[dst].append(tmp.pop())
        continue
    for i in range(1, 35, 4):
        c = line[i]
        if c == ' ': continue
        ar[i//4].append(c)

print(''.join(s[-1] for s in ar))