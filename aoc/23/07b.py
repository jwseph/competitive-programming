from utils import *

lines = readlines('07.in')

chs = 'J23456789TQKA'

def bestcalc(s, i):
    if i == len(s): return calc(s)
    if s[i] != 'J': return bestcalc(s, i+1)
    return max(bestcalc(s[:i] + c+s[i+1:], i+1) for c in chs)

def calc(s):
    if s[0] == s[1] == s[2] == s[3] == s[4]: return 7
    cnt = Counter(s)
    if cnt[s[0]] == 4 or cnt[s[1]] == 4: return 6
    arr = sorted(cnt.values())
    if arr == [2, 3]: return 5
    if 3 in arr: return 4
    if arr.count(2) == 2: return 3
    if 2 in arr: return 2
    return 1

def stren(s):
    return tuple('J23456789TQKA'.index(c) for c in s)

A = []
for line in lines:
    hand, bid = line.split()
    bid = int(bid)
    A.append((bestcalc(hand, 0), stren(hand), hand, bid))
A.sort()
res = 0
for i, (c, s, hand, bid) in enumerate(A):
    res += (i+1)*int(bid)
print(res)