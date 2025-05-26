from copy import deepcopy
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

def touching4(x, y, r, c):
    return abs(x-r) + abs(y-c) <= 1

def print_pts():
    a = [['.']*31 for _ in range(31)]
    for i in range(len(pts))[::-1]:
        a[pts[i][0]+15][pts[i][1]+15] = str(i)
    print('\n'.join(map(''.join, a)))
    print()

pts = [[0, 0] for _ in range(10)]
v = set()
for line in lines:
    d, amt = line.split()
    print(f'{amt=}')
    for _ in range(int(amt)):
        old = deepcopy(pts)
        dr, dc = d4[d]
        pts[0][0] += dr
        pts[0][1] += dc
        for i in range(9):
            if not touching(*pts[i], *pts[i+1]):
                if touching4(pts[i][0], pts[i][1], pts[i+1][0]+dr, pts[i+1][1]+0):
                    dc = 0
                if touching4(pts[i][0], pts[i][1], pts[i+1][0]+0, pts[i+1][1]+dc):
                    dr = 0
                if not touching4(pts[i][0], pts[i][1], pts[i+1][0]+dr, pts[i+1][1]+dc):
                    dr = old[i][0]-pts[i+1][0]
                    dc = old[i][1]-pts[i+1][1]
                pts[i+1][0] += dr
                pts[i+1][1] += dc
        v.add(tuple(pts[i+1]))
print(len(v))