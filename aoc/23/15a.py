from utils import *

lines = readlines('15.in')

ress = 0
for word in lines[0].split(','):
    res = 0
    for c in word:
        res += ord(c)
        res = res * 17 % 256
    ress += res

print(ress)