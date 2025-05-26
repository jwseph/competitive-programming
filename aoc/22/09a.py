lines = open('aoc/22/09.in').read().splitlines()
print(lines)

r = c = 0
d4 = {
    'R': (0, 1),
    'L': (0, -1),
    'U': (-1, 0),
    'D': (1, 0),
}
def touching(x, y, r, c):
    return max(abs(x-r), abs(y-c)) <= 1
x = y = 0
v = set()
for line in lines:
    d, amt = line.split()
    amt = int(amt)
    dr, dc = d4[d]
    for _ in range(amt):
        r += dr
        c += dc
        if not touching(x, y, r, c):
            x = r-dr
            y = c-dc
        v.add((x,y ))

print(len(v))