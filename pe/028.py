def sol(n):
    res = 1
    cur = 1
    for i in range(1, n+1):
        for _ in range(4):
            w = 2*i+1
            cur += w-1
            res += cur
    return res

def sol2(n):
    return (((16*n+30)*n+26)*n+3)//3

res = sol2(500)
print(res)