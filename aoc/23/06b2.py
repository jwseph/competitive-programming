from utils import *

lines = readlines('06.in')

times = lines[0].split()[1:]
distances = lines[1].split()[1:]

time = int(''.join(times))
distance = int(''.join(distances))

def qd(a, b, c):
    u = (b*b-4*a*c)**.5/2/a
    return -b/2/a+u, -b/2/a-u

l, r = qd(-1, time, -distance)
print(int(r)-ceil(l)+1)