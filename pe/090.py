from itertools import combinations

C = [tuple(map(int, str(i*i).rjust(2, '0'))) for i in range(1, 10)]

def sol(A, B):
    if A & {6, 9}: A |= {6, 9}
    if B & {6, 9}: B |= {6, 9}
    return all(x in A and y in B or y in A and x in B for x, y in C)

res = 0
for A in combinations(range(10), 6):
    for B in combinations(range(10), 6):
        if B > A: continue
        res += sol(set(A), set(B))
print(res)