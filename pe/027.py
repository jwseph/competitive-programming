N = 10**6
P = [True]*N
P[0] = P[1] = False
for i in range(2, int(N**.5)+1):
    if not P[i]: continue
    for j in range(i*i, N, i):
        P[j] = False

def sol(c):
    a, b = c
    n = 0
    while 0 <= (n+a)*n+b < N and P[(n+a)*n+b]:
        n += 1
    return n

res = max(((a, b) for a in range(-1000, 1001) for b in range(-1000, 1001)), key=sol)
print(res[0]*res[1])