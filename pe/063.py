res = 0
for a in range(1, 10):
    b = 1
    while len(str(a**b)) == b:
        res += 1
        b += 1
print(res)