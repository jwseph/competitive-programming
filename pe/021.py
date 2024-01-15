def d(n):
    res = 0
    for i in range(1, int(n**.5)+1):
        if n%i == 0:
            res += i
            if i != n//i:
                res += n//i
    return res-n

res = sum(x for x in range(1, 10**4) if d(d(x)) == x and d(x) != x)
print(res)