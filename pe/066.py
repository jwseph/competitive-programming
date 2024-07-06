from utils import CF
from math import isqrt

def sol(D):
    # https://en.wikipedia.org/wiki/Pell%27s_equation
    if isqrt(D)**2 == D: return 0
    A = CF.sqrt(D)
    N = len(A)-1
    return CF.approx(A[:-1] if N%2 == 0 else A+A[1:-1]).numerator

res = max(range(1001), key=sol)
print(res)