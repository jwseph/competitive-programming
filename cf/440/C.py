a = [0]
for _ in range(100):
    a.append(a[-1]*10+1)

def sol2(n):
    if n <= 1: return n
    i = 1
    while a[i] <= n: i += 1
    lo = n//a[i-1]*(i-1) + sol2(n%a[i-1])
    hi = i + (a[i]-n)//a[i-1]*(i-1) + sol2((a[i]-n)%a[i-1])
    return min(lo, hi)

print(sol2(int(input())))