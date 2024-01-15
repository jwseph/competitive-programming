def f(i):
    return i*f(i-1) if i else 1

K = 10**6-1
N = 10
A = list(range(N))

res = []
for i in range(N):
    s = f(N-1-i)
    res.append(A.pop(K//s))
    K %= s

print(''.join(map(str, res)))