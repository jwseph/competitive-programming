res = 0
a = 0
b = 1
while a < 4*10**6:
    if a%2 == 0: res += a
    a, b = b, a+b
print(res)