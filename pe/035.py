from utils import sieve

N = 10**6
P = sieve(N)

def circular(n):
    s = str(n)
    return all(P[int(s[i:] + s[:i])] for i in range(len(s)))

res = len(list(filter(circular, range(N))))
print(res)