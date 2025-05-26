from utils import *

a =(readlines('21.in'))

key = '0123456789A^<v>'
row = [3, 2, 2, 2, 1, 1, 1, 0, 0, 0, 3, 3, 4, 4, 4]
col = [1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 2, 1, 0, 1, 2]

def sol(s, n):
    res = []
    for c, d in pairwise('A'+s):
        i = key.index(c)
        j = key.index(d)
        dc = col[j]-col[i]
        dr = row[j]-row[i]

        if dr == 0 or dc == 0:
            for _ in range(dr): res.append('v')
            for _ in range(-dr): res.append('^')
            for _ in range(-dc): res.append('<')
            for _ in range(dc): res.append('>')
        elif dr < 0 and dc < 0:
            for _ in range(-dc): res.append('<')
            for _ in range(dc): res.append('>')
            for _ in range(dr): res.append('v')
            for _ in range(-dr): res.append('^')
        elif dr > 0 and dc < 0:
            for _ in range(-dc): res.append('<')
            for _ in range(dc): res.append('>')
            for _ in range(dr): res.append('v')
            for _ in range(-dr): res.append('^')
        elif dr < 0 and dc > 0:
            for _ in range(dr): res.append('v')
            for _ in range(-dr): res.append('^')
            for _ in range(-dc): res.append('<')
            for _ in range(dc): res.append('>')
        elif dr > 0 and dc > 0:
            for _ in range(-dc): res.append('<')
            for _ in range(dc): res.append('>')
            for _ in range(dr): res.append('v')
            for _ in range(-dr): res.append('^')

        res.append('A')
    if n == 0: return ''.join(res)
    return sol(''.join(res), n-1)

res = 0
for pat in a:
    cur = sol(pat, 2)
    print(len(cur), cur)
    # print(sol(pat, 1), sol(pat, 2), sol(pat, 2), len(sol(pat, 2)))
    res += int(pat[:3])*len(cur)
print(res)
'''
<<vA>>^AvA^A<<vA >>^AA<<vA>A>^AAvAA^<A>A<vA>^AA<A>A<<vA>A>^AAAvA^<A>A 68
<v<A>>^AvA^A<vA<A A>>^AAvA<^A>AAvA^A<vA>^AA<A>A<v<A>A>^AAAvA<^A>A

'''