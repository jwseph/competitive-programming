n = 600851475143
i = 2
res = -1
while i*i <= n:
    if n%i == 0: res = i
    while n%i == 0: n //= i
    i += 1
res = max(res, n)
print(res)