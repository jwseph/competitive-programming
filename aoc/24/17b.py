from utils import *

a = lines = readlines('17.in')

ar = getnums(lines[-1])
a = getnums(lines[0])[0]
b = getnums(lines[1])[0]
c = getnums(lines[2])[0]

def sol(a, b, c):
    i = 0
    res = []
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
            res.append(str(m%8))
        elif l == 6:
            b = a // 2**m
        elif l == 7:
            c = a // 2**m
        i += 2
    return ','.join(res)


# print(lines[-1].split()[1])
# for a in range(10**8):
#     if sol(a, b, c) == lines[-1].split()[1]:
#         print(a)


'''

a=28066687
b=0
c=0


5,5  print ( a&111  ^  a&111_11111111 >> ((a&111)^1)       % 8 )
0,3  a >>= 3
repeat until 0


[7, 1, 4, 4, 2, 0, 1, 3, 5, 6, 4, 1, 0, 0, 6, 5]
................................................

0b

a=0oXXX
b=0o100
c=0o


0 
a = 000 101







Repeat until a == 0

a=2024
b=0
c=0

0,3 trunc divide a by 2**3
5,4 print a%8



3,0 repeat until a != 0


'''


# ar = [2,4,1,1,7,5,4,6,0,3,1,4,5,5,3,0]
# ar = [[7, 1, 4, 4, 2, 0, 1, 3, 5, 6, 4, 1, 0, 0, 6, 5]]
# ar = [7, 1, 4, 4, 2, 0, 1, 3, 5, 6, 4, 1, 0, 0, 6, 5][::-1]


ar = [x^0b101 for x in ar][::-1]
@cache
def sol(x, i):
    if i == len(ar):
        print(x)
        return
    for k in range(8):
        y = x<<3 | k
        if (y ^ y>>(y%8^1)) % 8 == ar[i]:
            sol(y, i+1)
sol(0, 0)
# print([x^0b101 for x in ar])

# @cache
# def sol(i):
