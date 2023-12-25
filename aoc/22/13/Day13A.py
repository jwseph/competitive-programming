s = [pair.split('\n') for pair in open("Day13.in").read().strip().split("\n\n")]

def compare(l, r):
    if isinstance(l, list) and isinstance(r, int): r = [r]
    if isinstance(l, int) and isinstance(r, list): l = [l]
    if isinstance(l, int): return l-r
    for l_, r_ in zip(l, r):
        c = compare(l_, r_)
        if c != 0: return c
    return len(l)-len(r)

res = 0
for i, (l, r) in enumerate(s):
    if compare(eval(l), eval(r)) <= 0: res += i+1
print(res)
