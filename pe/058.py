from sympy import isprime

p = 0
t = x = w = 1
while not p or p/t >= .1:
    w += 2
    print(p/t)
    for _ in range(4):
        x += w-1
        p += isprime(x)
        t += 1
print(w)