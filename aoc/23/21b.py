from utils import *

A = readlines('21.in')

R = len(A)
C = len(A[0])

q = deque()
vst = set()

'''
3 - 160 +80
4 - 240 +320
5 - 560 +160
6 - 720 +480
7 - 1200 +240
8 - 1440 +640
9 - 2080 +320
10 - 2400 +800
11 - 3200

3,5,7,9,...,202300-1
4,6,8,10,...,202300-2
'''
def calc_error(n):
    ta = (n-1-3)//2+1
    ra = 80*ta*(ta+1)//2
    print('ra', ra)
    tb = (n-2-4)//2+1
    rb = tb*160 + 160*tb*(tb+1)//2
    print('rb', rb)
    return ra+rb+160

n = 202300
stepmax = 65+131*0

for r in range(R):
    for c in range(C):
        if A[r][c] == 'S':
            q.append((r, c))
            vst.add((r, c))
steps = 0
while len(q) and steps < stepmax:
    for _ in range(len(q)):
        r, c = q.popleft()
        adj = ((r-1, c), (r, c-1), (r+1, c), (r, c+1))
        for i, j in adj:
            if (i, j) in vst: continue
            if A[i%R][j%C] == '#': continue
            vst.add((i, j))
            q.append((i, j))
    steps += 1
res_tmp = sum((r+c)%2 == stepmax%2 for r, c in vst)
print(res_tmp)
# 65 odd: 3797
# 65 even: 3716
# 196 even: 34009
# dia: 3837 1step 3746 2step
#
# steps%2 == (r+c)%2
MAX = 26501365
# n = (MAX-130/2)//131

a1 = 3797
a2 = 3716
b1 = 3837
b2 = 3746
# print(9*a1+4*a2+4*b1+8*b2)
res = a1
# n = 3
# print(n)
# n = 202300
for i in range(n):
    res += 4*(i+1)*(b1 if i%2 == 0 else b2)
    res += 4*(i+1)*(a2 if i%2 == 0 else a1)
print(res)
print(res-res_tmp)
print(calc_error(n))
print('final res', res-calc_error(n))

# for r in range(-MAX2, MAX2+1):


print(R)  # 131
print(C)  # 131