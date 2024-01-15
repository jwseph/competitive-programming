def cycle(d):
    # 1/d == xxxx/(10**n-1)
    # d*xxxx == 10**n-1
    # 10**n-1 == 0 (mod d)
    # 10**n == 1 (mod d)

    while d%2 == 0: d //= 2
    while d%5 == 0: d //= 5
    if d == 1: return 0

    cur = 1
    n = 0
    while n == 0 or cur != 1:
        cur = cur*10 % d
        n += 1
    return n

res = max(range(1, 1000), key=cycle)
print(res)