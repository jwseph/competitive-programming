N = 10**6

def pal(s):
    return s == s[::-1]

def calc(i):
    return pal(str(i)) and pal(bin(i)[2:])

res = list(filter(calc, range(N)))
print(sum(res))