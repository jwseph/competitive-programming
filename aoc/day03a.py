A = open('aoc/day03.in').read().splitlines()

R = len(A)
C = len(A[0])

def symbol(r, c):
    if r < 0 or r >= R or c < 0 or c >= C: return False
    return not A[r][c].isdigit() and A[r][c] != '.'

def sol(r1, c1, c2):
    if c1 == c2: return False
    for c in range(c1-1, c2+1):
        for r in range(r1-1, r1+2):
            if symbol(r, c):
                return True
    return False

res = 0
for r in range(R):
    j = 0
    for c in range(C):
        if not A[r][c].isdigit():
            if sol(r, j, c):
                res += int(A[r][j:c])
            j = c+1
    if sol(r, j, C):
        res += int(A[r][j:C])

print(res)