lines = open('aoc/day01.in').read().splitlines()

digits = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
}

def fd(s, rev):
    if rev: s = s[::-1]
    words = {
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9,
    }
    m = words | digits
    res = 10**9
    for word, cur in m.items():
        if rev: word = word[::-1]
        i = s.find(word)
        if i < 0: continue
        if i < res:
            res = i
            res_val = cur
    return res_val

res = sum(fd(line, False)*10 + fd(line, True) for line in lines)
print(res)