N = 3*10**3
A = [i*(3*i-1)//2 for i in range(1, N+1)]
S = set(A)
res = 10**9
for j in range(N):
    for i in range(j):
        if A[j]-A[i] in S and A[i]+A[j] in S:
            res = min(res, A[j]-A[i])
print(res)