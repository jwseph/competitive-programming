from collections import Counter
import requests

S = requests.get('https://projecteuler.net/resources/documents/0054_poker.txt').text

def sol(hand):
    X, Y = zip(*hand)
    X = sorted('AKQJT98765432'.index(x) for x in X)
    X = sorted(X, key=X.count, reverse=True)
    C = sorted(Counter(X).values(), reverse=True)
    f = all(u == v for u, v in zip(Y, Y[1:]))
    s = all(v-u == 1 for u, v in zip(X, X[1:]))
    if X[0] == 0 and s and f: return (0, *X)
    if s and f: return (1, *X)
    if C[0] == 4: return (2, *X)
    if C == [3, 2]: (3, *X)
    if f: return (4, *X)
    if s: return (5, *X)
    if C[0] == 3: return (6, *X)
    if C[:2] == [2, 2]: return (7, *X)
    if C[0] == 2: return (8, *X)
    return (9, *X)

res = 0
for line in S.splitlines():
    row = line.split()
    A, B = row[:5], row[5:]
    res += sol(A) < sol(B)

print(res)