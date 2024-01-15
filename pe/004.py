A = {a*b for b in range(100, 1000) for a in range(100, b)}
res = max(x for x in A if str(x) == str(x)[::-1])
print(res)