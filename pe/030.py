N = 5
res = 0
for i in range(2, 2*10**6):
    if i == sum(int(d)**N for d in str(i)):
        res += i
        print(i)
print(res)