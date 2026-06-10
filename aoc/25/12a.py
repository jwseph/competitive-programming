from utils import *

hash_cnt = [7, 7, 6, 5, 7, 7]

def sol(n, m, cnt):
    if sum(cnt) <= n//3*(m//3): return True
    if sum(map(mul, hash_cnt, cnt)) > n*m: return False
    return None


lines = readlines('12.in')
lines = lines[5*6:]
res = 0
for line in lines:
    left, right = line.split(': ')
    n, m = map(int, left.split('x'))
    cnt = list(map(int, right.split()))
    res += sol(n, m, cnt)
print(res)
    
exit()

# for i in range(6):


i = len(lines)-1 - lines[::-1].index('')
# shapes = [:]

if __name__ == '__main__':
    import time
    date = input('Enter date: ')
    print('Solving...')
    t = time.perf_counter()
    res = solve(date)
    print(f'Solved in {time.perf_counter()-t:.3f}s')
    for r in range(R):
        for c in range(C):
            if res[r][c] <= 101:
                print('.', end=' ')
                continue
            print(chr(res[r][c]-201+ord('0')), end=' ')
        print()