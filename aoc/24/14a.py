from utils import *

lines = readlines('14.in')
n = len(lines)

nc = 103
nr = 101

quad = [0, 0, 0, 0]
for line in lines:
    pr, pc, vr, vc = getnums(line)
    r = (pr+100*vr)%nr #103
    c = (pc+100*vc)%nc #101
    if r == nr//2 or c == nc//2: continue
    quad[int(r < nr//2) + int(c < nc//2)*2] += 1

print(prod(quad))