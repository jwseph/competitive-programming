import requests

r = requests.get('https://projecteuler.net/resources/documents/0059_cipher.txt')
A = list(map(int, r.text.split(',')))

def sol(S):
    return sum(c.isalpha() or c == ' ' for c in S)

res = []
for a in range(97, 123):
    for b in range(97, 123):
        for c in range(97, 123):
            S = ''.join(chr(x^[a, b, c][i%3]) for i, x in enumerate(A))
            res.append(S)

S = max(res, key=sol)
print(S)
print(sum(map(ord, S)))