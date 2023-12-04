lines = open('aoc/day04.in').read().splitlines()

def sol(line):
    card, not_card = line.split(': ')
    l, r = not_card.split(' | ')
    a = list(map(int, l.split()))
    b = set(map(int, r.split()))
    res = 0
    for num in a:
        if num in b:
            res += 1
    return res

N = len(lines)
cnt = [1]*(N+10)
for i in range(N):
    cur = sol(lines[i])
    for j in range(i+1, i+1+cur):
        cnt[j] += cnt[i]

print(sum(cnt[:N]))