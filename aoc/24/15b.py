from utils import *

a, moves = grouplines(readlines('15.in'))
moves = ''.join(moves)

a = [list(''.join({'#': '##', 'O': '[]', '.': '..', '@': '@.'}[c] for c in row)) for row in a]

n = len(a)
m = len(a[0])

for r in range(n):
    a[r] = list(a[r])
    for c in range(m):
        if a[r][c] == '@':
            rr, rc = r, c

for move in moves[:]:
    dr, dc = d4['>^<v'.index(move)]
    if dr == 0:
        nr, nc = rr, rc
        pos = [(rr, rc)]
        nr += dr
        nc += dc
        pos.append((nr, nc))
        while a[nr][nc] in '[]':
            nr += dr
            nc += dc
            pos.append((nr, nc))
        if a[nr][nc] == '#':
            continue
        for (r1, c1), (r2, c2) in pairwise(pos[::-1]):
            a[r1][c1] = a[r2][c2]
        a[rr][rc] = '.'
        rr += dr
        rc += dc
        continue
    
    q = deque()
    v = set()
    q.append((rr, rc))
    v.add((rr, rc))
    pos = []
    ok = True
    while q:
        r, c = q.popleft()
        if a[r][c] == '.':continue
        if a[r][c] == '#':
            ok = False
            break
        pos.append((r, c))
        if a[r][c] in '[]':
            if a[r][c] == '[':
                if (r, c+1) not in v:
                    q.append((r, c+1))
                    v.add((r, c+1))
            if a[r][c] == ']':
                if (r, c-1) not in v:
                    q.append((r, c-1))
                    v.add((r, c-1))
        q.append((r+dr, c))
        v.add((r+dr, c))

    if not ok: continue
    pos.sort(reverse=(dr > 0))
    for r, c in pos:
        a[r+dr][c] = a[r][c]
        a[r][c] = '.'
    rr += dr
    rc += dc

    '''
    #
    []  []
     [][]
      []

    '''

res = 0
for r in range(n):
    for c in range(m):
        if a[r][c] != '[': continue
        res += 100*r+c
print(res)