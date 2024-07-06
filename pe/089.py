from utils import Roman
import requests

A = requests.get('https://projecteuler.net/resources/documents/0089_roman.txt').text.split()

res = 0
for s in A:
    print(s, '->', Roman(s))
    res += len(s) - len(str(Roman(s)))
print(res)