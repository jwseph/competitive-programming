from functools import cmp_to_key

lines = [line for line in open("Day13.in").read().strip().split("\n") if line]

def compare(l, r):
    if isinstance(l, list) and isinstance(r, int): r = [r]
    if isinstance(l, int) and isinstance(r, list): l = [l]
    if isinstance(l, int): return l-r
    for l_, r_ in zip(l, r):
        c = compare(l_, r_)
        if c != 0: return c
    return len(l)-len(r)

p1, p2 = [[2]], [[6]]
arr = list(map(eval, lines))+[p1, p2]
arr.sort(key=cmp_to_key(compare))
print((1+arr.index(p1))*(1+arr.index(p2)))
