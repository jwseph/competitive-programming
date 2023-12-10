A = open('aoc/day10.in').read().splitlines()

def get_d(dr, dc, c):
    if c == '|' or c == '-': return dr, dc
    if dr == 1:
        if c == 'L': return 0, 1
        if c == 'J': return 0, -1
    if dr == -1:
        if c == '7': return 0, -1
        if c == 'F': return 0, 1
    if dc == -1:
        if c == 'L': return -1, 0
        if c == 'F': return 1, 0
    if dc == 1:
        if c == 'J': return -1, 0
        if c == '7': return 1, 0

R = len(A)
C = len(A[0])

a, b = -1, -1
for r in range(R):
    if 'S' in A[r]:
        a, b = r, A[r].index('S')

n = 1
for da, db in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
    i = a+da
    j = b+db
    if get_d(da, db, A[i][j]):
        r, c = i, j
        dr, dc = da, db
        break

while A[r][c] != 'S':
    n += 1
    dr, dc = get_d(dr, dc, A[r][c])
    r += dr
    c += dc

print(n)
print(n//2)