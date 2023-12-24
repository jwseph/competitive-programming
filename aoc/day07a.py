from utils import *

lines = open('aoc/day07.in').read().splitlines()

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
    return tuple('23456789TJQKA'.index(c) for c in s)

A = []
for line in lines:
    hand, bid = line.split()
    bid = int(bid)
    A.append((calc(hand), stren(hand), hand, bid))
A.sort()
res = 0
for i, (c, s, hand, bid) in enumerate(A):
    res += (i+1)*int(bid)
print(res)