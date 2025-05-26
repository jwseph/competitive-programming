from utils import *

a = lines = readlines('17.in')

ar = getnums(lines[-1])
a = getnums(lines[0])[0]
b = getnums(lines[1])[0]
c = getnums(lines[2])[0]
i = 0
while i+1 < len(ar):
    l = ar[i]
    r = ar[i+1]
    m = r
    if r == 4: m = a
    if r == 5: m = b
    if r == 6: m = c
    assert r != 7
    if l == 0:
        a //= 2**m
    elif l == 1:
        b ^= r
    elif l ==2 :
        b = m%8
    elif l == 3:
        if a:
            i = r-2
    elif l == 4:
        b = b^c
    elif l == 5:
        print(m%8, end=',')
    elif l == 6:
        b = a // 2**m
    elif l == 7:
        c = a // 2**m
    i += 2
