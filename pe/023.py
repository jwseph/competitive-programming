def d(n):
    res = 0
    for i in range(1, int(n**.5)+1):
        if n%i == 0:
            res += i
            if i != n//i:
                res += n//i
    return res-n

MAX = 21000
A = set(x for x in range(1, MAX) if d(x) > x)
res = 0
for i in range(MAX):
    if any(i-x in A for x in A): continue
    res += i
print(res)