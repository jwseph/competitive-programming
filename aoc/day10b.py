A = open('aoc/day10.in').read().splitlines()

left = right = 0

def get_d(dr, dc, c):
    global left, right
    if c == '|' or c == '-': return dr, dc
    if dr == 1:
        if c == 'L':
            left += 1
            return 0, 1
        if c == 'J':
            right += 1
            return 0, -1
    if dr == -1:
        if c == '7':
            left += 1
            return 0, -1
        if c == 'F':
            right += 1
            return 0, 1
    if dc == -1:
        if c == 'L':
            right += 1
            return -1, 0
        if c == 'F':
            left += 1
            return 1, 0
    if dc == 1:
        if c == 'J':
            left += 1
            return -1, 0
        if c == '7':
            right += 1
            return 1, 0

R = len(A)
C = len(A[0])

a, b = -1, -1
for r in range(R):
    if 'S' in A[r]:
        a, b = r, A[r].index('S')
    A[r] = list(A[r])

res = 0
def dfs(r, c):
    if r < 0 or r >= R or c < 0 or c >= C: return
    if A[r][c] == 'S': return
    A[r][c] = 'S'
    global res
    res += 1
    for i, j in [(r+1, c), (r-1, c), (r, c+1), (r, c-1)]:
        dfs(i, j)

n = 1
for da, db in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
    i = a+da
    j = b+db
    if get_d(da, db, A[i][j]):
        r, c = i, j
        dr, dc = da, db
        break
# left=4353 right=4350
q = []
left = right = 0
while A[r][c] != 'S':
    n += 1
    q.append((r-dc, c+dr))  # use r+dc, c-dr if right > left
    dr, dc = get_d(dr, dc, A[r][c])
    q.append((r-dc, c+dr))
    A[r][c] = 'S'
    r += dr
    c += dc
for r, c in q:
    dfs(r, c)

print(left, right)
print(res)