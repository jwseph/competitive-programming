import requests

A = eval('[' + requests.get('https://projecteuler.net/resources/documents/0022_names.txt').text + ']')
A.sort()
res = sum((i+1) * sum(ord(c)-ord('A')+1 for c in s) for i, s in enumerate(A))
print(res)