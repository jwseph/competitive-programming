N = 10**6
P = [True]*N
P[0] = P[1] = False
for i in range(int(N**.5)+1):
    if not P[i]: continue
    for j in range(i*i, N, i):
        P[j] = False

def calc(x):
    if len(str(x)) == 1: return False
    y = 1
    while x//y:
        for a in [x%(y*10), x//y]:
            if not P[a]: return False
        y *= 10
    return True

res = list(filter(calc, range(N)))
print(sum(res))