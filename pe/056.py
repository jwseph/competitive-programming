N = 100
res = 0

for a in range(N):
    for b in range(N):
        res = max(res, sum(map(int, str(a**b))))
print(res)