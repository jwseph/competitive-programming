N = 1000
A = {i*i: i for i in range(1, N)}

for a in range(N):
    for b in range(a+1, N):
        if a*a+b*b not in A: continue
        c = A[a*a+b*b]
        if a+b+c == 1000:
            res = a*b*c
print(res)