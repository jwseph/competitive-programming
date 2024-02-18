check = [-1, -1, -1, -1, 2, 3, 5, 7, 11, 13, 17]

def sol(i, v=0, cur=0):
    if check[i] >= 0 and cur%1000%check[i] != 0: return 0
    if i == 10: return cur
    res = 0
    for d in range(10):
        if v&1<<d: continue
        if d == 0 and i == 0: continue
        res += sol(i+1, v|1<<d, cur*10+d)
    return res

res = sol(0)
print(res)