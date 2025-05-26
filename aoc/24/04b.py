from utils import *
import requests

a = readlines('04.in')
print(readlines('04.in') == getlines(2024, 4))
n = len(a)
m = len(a[0])

res = 0
for r in range(1, n-1):
    for c in range(1, m-1):
        s = ''.join(a[r+dr][c+dc] for dr, dc in d8[1::2])
        res += a[r][c] == 'A' and s in 'MMSS'*2
print(res)

if __name__ == '__main__':
    r = requests.get('https://adventofcode.com/2024/day/4/input')
    s = r.text
    print(len(s))
    print(len('\n'.join(a)))