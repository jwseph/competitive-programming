mod = 998244353

nt = int(input())
for t in range(1, nt+1):
    w, g, l = map(int, input().split())
    print((2*l+1)*(w-g) % mod)