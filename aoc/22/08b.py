ar = open('aoc/22/08.in').read().splitlines()
ar = list(map(list, ar))

br = list(zip(*ar))

n = len(ar)
m = len(ar[0])

def sol(v, s):
    res = 0
    for c in s:
        res += 1
        if c >= v: break
    return res

res = 0
for r in range(n):
    for c in range(m):
        v = ar[r][c]
        cur = sol(v, ar[r][:c][::-1]) * sol(v, ar[r][c+1:]) * sol(v, br[c][:r][::-1]) * sol(v, br[c][r+1:])
        res = max(res, cur)

print(res)

# 5:10