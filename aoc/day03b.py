A = open('aoc/day03.in').read().splitlines()

R = len(A)
C = len(A[0])

G = [[[] for c in range(C)] for r in range(R)]

def symbol(r, c, cur):
    if r < 0 or r >= R or c < 0 or c >= C: return False
    if A[r][c] == '*': G[r][c].append(cur)

def sol(r1, c1, c2):
    if c1 == c2: return
    cur = int(A[r1][c1:c2])
    for c in range(c1-1, c2+1):
        for r in range(r1-1, r1+2):
            symbol(r, c, cur)
    return

res = 0
for r in range(R):
    j = 0
    for c in range(C):
        if not A[r][c].isdigit():
            sol(r, j, c)
            j = c+1
    sol(r, j, C)

for r in range(R):
    for c in range(C):
        if len(G[r][c]) == 2:
            res += G[r][c][0]*G[r][c][1]

print(res)