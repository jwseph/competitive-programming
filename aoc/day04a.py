lines = open('aoc/day04.in').read().splitlines()

def sol(line):
    card, not_card = line.split(': ')
    l, r = not_card.split(' | ')
    a = list(map(int, l.split()))
    b = set(map(int, r.split()))
    res = 0
    for num in a:
        if num in b:
            res += 1
    if not res: return 0
    return 2**(res-1)

res = sum(sol(line) for line in lines)
print(res)