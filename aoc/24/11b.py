from utils import *

a = list(map(int, readlines('11.in')[0].split()))
n = len(a)
print(a)

cnt = Counter(a)
for _ in range(75):
    cnt2 = Counter()
    for x, cx in cnt.items():
        if x == 0:
            cnt2[1] += cx
            continue
        if len(str(x)) %2 == 0:
            s = str(x)
            cnt2[int(s[:len(s)//2])] += cx
            cnt2[int(s[len(s)//2:])] += cx
            continue
        cnt2[x*2024] += cx
    cnt = cnt2

print(sum(cnt.values()))