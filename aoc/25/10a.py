from utils import *

lines = readlines('10.in')

def sol(target, buttons):
    q0 = [target]
    vst = {target}
    for t in range(10**10):
        q1 = []
        for i in q0:
            if i == 0: return t
            for b in buttons:
                j = i^b
                if j in vst: continue
                vst.add(j)
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
    
    buttons = []
    for group in middle.split():
        buttons.append(sum(1<<int(s) for s in group[1:-1].split(',')))
    
    res += sol(target, buttons)

print(res)