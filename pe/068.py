from itertools import permutations

def check(A, B):
    return len({A[i]+B[i-1]+B[i] for i in range(5)}) == 1

def string(A, B):
    return int(''.join(f'{A[i]}{B[i-1]}{B[i]}' for i in range(5)))

res = 0

# 6 7 8 9 10 must be on outside
for A in permutations(range(6, 11)):
    if A[0] != 6: continue
    for B in permutations(range(1, 6)):
        if check(A, B):
            res = max(res, string(A, B))

print(res)