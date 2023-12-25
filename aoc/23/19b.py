from utils import *

lines1, lines2 = read('19.in').split('\n\n')
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
    if name == 'A':
        res = 1
        for k, (l, r) in x.items():
            sz = max(0, r-l+1)
            res *= sz
        return res
    # print(name, x)
    d = M[name]
    res = 0
    for name2, ext in d:
        if ext[0] == 0:
            y = deepcopy(x)
            y[ext[1]][1] = min(y[ext[1]][1], ext[2]-1)
            res += sol(y, name2)
            x[ext[1]][0] = max(x[ext[1]][0], ext[2])
        if ext[0] == 1:
            y = deepcopy(x)
            y[ext[1]][0] = max(y[ext[1]][0], ext[2]+1)
            res += sol(y, name2)
            x[ext[1]][1] = min(x[ext[1]][1], ext[2])
        if ext[0] == 2:
            res += sol(x, name2)
    return res

start = {ch: [1, 4000] for ch in 'xmas'}
print(sol(start, 'in'))