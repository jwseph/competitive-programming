N = 2*10**6
P = [True]*N
P[0] = P[1] = False
for i in range(2, int(N**.5)+1):
    if not P[i]: continue
    for j in range(i*i, N, i):
        P[j] = False

res = sum(i*P[i] for i in range(N))
print(res)