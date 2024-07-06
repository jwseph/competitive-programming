ops = '+-*/'
A = [f'4 {a} 4 {b} 4 {c} 4' for a in ops for b in ops for c in ops]

def sol(S):
    try: return eval(S.replace('/', '//'))
    except ZeroDivisionError: return None

M = {}
for S in A:
    a = sol(S)
    M[a] = f'{S} = {a}'

N = int(input())
for _ in range(N):
    a = int(input())
    print(M.get(a, 'no solution'))