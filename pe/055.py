def calc(x, n=55):
    s = str(x)
    if n < 55 and s == s[::-1]: return False
    if n == 0: return True
    return calc(x+int(s[::-1]), n-1)

N = 10**4

res = list(filter(calc, range(N+1)))
print(len(res))