from utils import *

lines = open('aoc/day15.in').read().splitlines()

ress = 0
for word in lines[0].split(','):
    res = 0
    for c in word:
        res += ord(c)
        res = res * 17 % 256
    ress += res

print(ress)