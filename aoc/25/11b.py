from utils import *

lines = readlines('11.in')

a = defaultdict(list)
for line in lines:
    i, right = line.split(': ')
    for j in right.split():
        a[i].append(j)

@cache
def sol(i):
    if i == 'out': return [1, 0, 0, 0]  # none, dac, fft, dac and fft
    res = [0, 0, 0, 0]  # 1<<0: dac, 1<<1: fft
    for j in a[i]:
        cur = sol(j)
        for dac in range(2):
            for fft in range(2):
                take = cur[dac<<0 | fft<<1]
                dac = dac or i == 'dac'
                fft = fft or i == 'fft'
                res[dac<<0 | fft<<1] += take
    return res

print(sol('svr'))