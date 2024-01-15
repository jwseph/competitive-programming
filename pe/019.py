def leap(y):
    return y%4 == 0 and y%100 != 0 or y%400 == 0

cur = (1+365)%7
res = 0
for y in range(1901, 2001):
    ms = [31, 28+leap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    for m in ms:
        res += cur == 0
        cur = (cur+m)%7
print(res)