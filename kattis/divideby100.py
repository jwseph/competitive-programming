A, B = input(), input()
S = '0'*(len(B)-len(A)) + A
d = len(B)-1
L, R = S[:-d].lstrip('0'), S[-d:].rstrip('0')
if not L: L = '0'
dot = '.'
if not R: dot = ''
print(L+dot+R)