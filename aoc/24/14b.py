from utils import *

lines = readlines('14.in')
n = len(lines)

nc = 103
nr = 101

i = 0
v_boards = set()
while True:
    v = set()
    cnt = Counter()
    tl = 0
    tr = 0
    for line in lines:
        pr, pc, vr, vc = getnums(line)
        r = (pr+i*vr)%nr #103
        c = (pc+i*vc)%nc #101
        v.add((r, c))
        cnt[r, c] += 1
        tl += r < nr//4 and c < nc//16
        tr += nr-r-1 < nr//4 and nc-c-1 < nc//16
    if len(cnt) == len(v) and tl == tr == 0:
        print(i)
        board = '\n'.join([''.join(['1' if (r,c) in v else '.' for c in range(nc)]) for r in range(nr)])
        if board in v_boards: continue
        v_boards.add(board)
        print(board, '\n\n')
    i += 1