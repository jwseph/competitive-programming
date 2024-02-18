def pan(i, n):
    return ''.join(str(i*d) for d in range(1, n+1))

def calc(n):
    return ''.join(sorted(n)) == '123456789'

x = [pan(i, n) for i in range(1, 10**4) for n in range(2, 10)]
y = list(filter(calc, x))

print(max(map(int, y)))