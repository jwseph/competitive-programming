from utils import *

s = readlines('09.in')[0]
print(len(s))

fs = []
gaps = SortedList()
pos = 0
for i, c in enumerate(s):
    if i%2 == 0:
        fs.append((pos, int(c), i//2))
    else:
        gaps.add([pos, int(c)])
    pos += int(c)
res = 0
for l, n, f in fs[::-1]:
    gap = None
    for gl, gn in gaps:
        if gl >= l: break
        if n <= gn:
            gap = [gl, gn]
            break
    if gap is not None:
        gl, gn = gap
        gaps.remove(gap)
        gap2 = [gl+n, gn-n]
        if gn-n:
            gaps.add(gap2)
            i = gaps.index(gap2)
            if i and gaps[i-1][0] + gaps[i-1][1] == gap2[0]:
                gaps.remove(gap2)
                gaps[i-1][1] += gap2[1]
            elif i+1 < len(gaps) and gap2[0] + gap2[1] == gaps[i+1][0]:
                gaps.remove(gap2)
                gaps[i][1] += gap2[1]
                gaps[i][0] = gap2[0]
        l = gl
    res += (n*l + n*(n-1)//2) * f
print(res)