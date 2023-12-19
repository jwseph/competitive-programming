from utils import *

lines1, lines2 = open('aoc/day19.in').read().strip().split('\n\n')
lines1 = lines1.splitlines()
lines2 = lines2.splitlines()

M = {}

for line in lines1:
    line = line[:-1]
    i, other = line.split('{')
    M[i] = []
    for rule in other.split(',')[:-1]:
        a, b = rule.split(':')
        if '<' in a:
            k, num = a.split('<')
            num = int(num)
            ext = 0, k, num
        elif '>' in a:
            k, num = a.split('>')
            num = int(num)
            ext = 1, k, num
        M[i].append((b, ext))
    for rule in other.split(',')[-1:]:
        b = rule
        M[i].append((b, (2,)))

def sol(x, name):
    if name == 'R': return 0
    if name == 'A': return 1
    d = M[name]
    for name2, ext in d:
        if ext[0] == 0:
            if x[ext[1]] < ext[2]: return sol(x, name2)
        if ext[0] == 1:
            if x[ext[1]] > ext[2]: return sol(x, name2)
        if ext[0] == 2:
            return sol(x, name2)
    return 0

res = 0

for line in lines2:
    line=line[1:-1]
    x = {}
    for obj in line.split(','):
        k, v = obj.split('=')
        x[k] = int(v)
    if sol(x, 'in'):
        res += sum(x.values())

print(res)