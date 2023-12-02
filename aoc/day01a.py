lines = open('aoc/day01.in').read().splitlines()

def fd(s):
    for c in s:
        if c.isdigit(): return int(c)

res = sum(fd(line)*10 + fd(line[::-1]) for line in lines)
print(res)