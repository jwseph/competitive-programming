import requests
from collections import defaultdict, deque

S = requests.get('https://projecteuler.net/resources/documents/0079_keylog.txt').text
IN = defaultdict(set)
A = defaultdict(set)
for s in S.split():
    for i, j in zip(s, s[1:]):
        A[i].add(j)
        IN[j].add(i)

Q = deque()
for i in A:
    if not IN[i]:
        Q.append(i)
res = ''
while Q:
    i = Q.popleft()
    res += i
    for j in A[i]:
        if not IN[j]: continue
        IN[j] -= {i}
        if not IN[j]:
            Q.append(j)
print(res)