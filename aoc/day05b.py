seeds, rest = open('aoc/day05.in').read().strip().split('\n\n', 1)
seeds = seeds.removeprefix('seeds: ').split(' ')
seeds = list(map(int, seeds))
A = [(a, a+b-1) for a, b in zip(seeds[::2], seeds[1::2])]
print(A)
B = []

for line in rest.split('\n'):
    if '-' in line or not line:
        if len(B): A += B
        B = []
        print()
        print(A)
        print()
        continue
    a, b, c = list(map(int, line.split(' ')))
    print('- ', a, b, c)
    for i, (l, r) in list(enumerate(A.copy()))[::-1]:
        if r < b or b+c <= l: continue
        invs = []
        if l < b: invs.append((l, b-1))
        if b+c-1 < r: invs.append((b+c, r))
        del A[i]
        A += invs
        d = b-a
        l = max(l, b)
        r = min(b+c-1, r)
        B.append((l-d, r-d))

A += B
print(A)
print(min(A))