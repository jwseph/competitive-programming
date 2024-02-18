import requests
from math import isqrt

S = requests.get('https://projecteuler.net/resources/documents/0042_words.txt').text
A = eval(f'[{S.lower()}]')

def calc(s):
    x = 1+8*sum(ord(c)-ord('a')+1 for c in s)
    return x == isqrt(x)**2

res = list(map(calc, A))
print(sum(res))