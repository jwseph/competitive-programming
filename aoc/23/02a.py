from utils import *

lines = readlines('02.in')

maxes = {
    'blue': 14,
    'green': 13,
    'red': 12,
}

def sol(s):
    s = s.split(' ', 2)[2]
    parts = s.split(';')
    for part in parts:
        part = part.strip()
        for item in part.split(', '):
            a, b = item.split()
            if not int(a) <= maxes[b]: return False
    return True

res = sum(i+1 for i, line in enumerate(lines) if sol(line))
print(res)