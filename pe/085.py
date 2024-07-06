N = 2*10**6

def sol(w, h):
    return w*(w+1)//2 * h*(h+1)//2

res = (0, 0)
for w in range(1, int(N**.5+1)):
    l, r = 0, N
    while l < r:
        h = (l+r+1)//2
        if sol(w, h) <= N: l = h
        else: r = h-1
    res = min(res, (w, h), (w, h+1), key=lambda t: abs(sol(*t)-N))
print(res, res[0]*res[1])