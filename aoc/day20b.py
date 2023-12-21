from utils import *

lines = open('aoc/day20.in').read().splitlines()

adj = {}
module_type = {}
data = {}
data2 = {}

for line in lines:
    left, right = line.split(' -> ')
    right = right.split(', ')
    if left != 'broadcaster':
        loc = left[1:]
        module_type[loc] = left[0]
        data[loc] = 0
    else:
        loc = 'broadcaster'
        module_type[loc] = left[0]
    adj[loc] = right

for loc in module_type:
    if module_type[loc] != '&': continue
    data2[loc] = {loc2: 0 for loc2 in module_type if loc in adj[loc2]}

from collections import deque

res = [0]*2
presses = 0
vst = {'ln': 0, 'dr': 0, 'zx': 0, 'vn': 0}
def push():  # ln dr zx vn
    q = deque()
    q.append(('broadcaster', 0, 'button'))
    res[0] += 1
    while len(q):
        loc, pulse, src = q.popleft()
        if loc == 'kj' and src in vst and not vst[src] and pulse == 1:
            print(src)
            vst[src] = presses
        # if loc == 'rx' and pulse == 0:
        #     print('done')
        if loc not in module_type: continue
        if module_type[loc] == '%':
            if pulse == 1: continue
            data[loc] = 1-data[loc]
            pulse = data[loc]
        if module_type[loc] == '&':
            data2[loc][src] = pulse
            data[loc] = 1-all(data2[loc].values())
            pulse = data[loc]
        for loc2 in adj[loc]:
            res[pulse] += 1
            q.append((loc2, pulse, loc))
for _ in range(100000):
    presses += 1
    push()
print(vst)
print(res[0]*res[1])
r = 1
for p in vst.values():
    r *= p
print(r)