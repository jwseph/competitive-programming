from utils import *

lines = readlines('10.in')

def hash_cnt(cnt: Counter):
    return hash(tuple(sorted(cnt.items())))

def sol(joltage, buttons):
    print(f'{joltage=} {buttons=}')
    q0 = [Counter()]
    vst = {tuple(q0[0].values())}
    for t in range(10**10):
        q1 = []
        for i in q0:
            if i == joltage: return t
            for b in buttons:
                j = i+b
                if j-joltage: continue
                h = hash_cnt(j)
                if h in vst: continue
                vst.add(h)
                q1.append(j) 
        q0 = q1
    return 'uh oh'

res = 0

for line in lines:
    left, other = line.split('] ')
    left = left[1:]
    middle, right = other.split(' {')
    right = right[:-1]
    
    target = 0
    for i, c in enumerate(left):
        target |= (c == '#') << i
    
    joltage = Counter({i: int(s) for i, s in enumerate(right.split(','))})
    
    buttons = []
    for group in middle.split():
        buttons.append(Counter(int(s) for s in group[1:-1].split(',')))
    
    res += sol(joltage, buttons)

print(res)