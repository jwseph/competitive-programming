ar = open('aoc/22/08.in').read().splitlines()
ar = list(map(list, ar))

br = list(zip(*ar))

n = len(ar)
m = len(ar[0])


res = 0
for r in range(n):
    for c in range(m):
        cur = False
        if max(ar[r][:c], default='-') < ar[r][c]:
            cur = True
        if max(ar[r][c+1:], default='-') < ar[r][c]:
            cur = True
        if max(br[c][:r], default='-') < ar[r][c]:
            cur = True
        if max(br[c][r+1:], default='-') < ar[r][c]:
            cur = True
        res += cur

print(res)