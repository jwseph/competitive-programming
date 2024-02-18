from utils import sieve

P = sieve(10**4)
K = 3330

for i in range(10**3, 10**4-2*K):
    A = [i, i+K, i+2*K]
    if all(P[a] and sorted(str(a)) == sorted(str(A[0])) for a in A):
        print(''.join(map(str, A)))