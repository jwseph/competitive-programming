def calc(i):
    for k in range(2, 7):
        if sorted(str(i)) != sorted(str(i*k)): return False
    return True

for i in range(1, 10**7):
    if calc(i):
        print(i)
        break