from utils import *

lines = readlines('02.in')

def sol(s):
    s = s.split(' ', 2)[2]
    parts = s.split(';')
    cnt = {
        'blue': 0,
        'green': 0,
        'red': 0,
    }
    for part in parts:
        part = part.strip()
        for item in part.split(', '):
            a, b = item.split()
            cnt[b] = max(cnt[b], int(a))
    return cnt['blue'] * cnt['green'] * cnt['red']

res = sum(sol(line) for i, line in enumerate(lines))
print(res)