from math import factorial as f

N = 10**5

def calc(x):
    return sum(f(d) for d in map(int, str(x)))

res = sum(x for x in range(10, N) if x == calc(x))
print(res)