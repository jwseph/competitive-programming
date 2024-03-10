from utils import CF

res = sum(len(CF.sqrt(n))%2 == 0 for n in range(10**4+1))
print(res)