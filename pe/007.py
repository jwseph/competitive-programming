N = 10**6
K = 10001
P = [True] * N
P[0] = P[1] = False
for i in range(2, int(N**.5)+1):
    if not P[i]: continue
    for j in range(i*i, N, i):
        P[j] = False
cur = 0
for i in range(N):
    cur += P[i]
    if cur == K:
        print(i)
        break