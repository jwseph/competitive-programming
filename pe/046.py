from sympy import isprime

V = set()

for i in range(1, 10**4):
    if not isprime(i): continue
    for j in range(1, 10**2):
        V.add(i+2*j*j)

res = 3
while isprime(res) or res in V: res += 2
print(res)