from utils import *

lines = readlines('06.in')

times = lines[0].split()[1:]
distances = lines[1].split()[1:]

res = 1

for time, distance in zip(times, distances):
    time = int(time)
    distance = int(distance)
    l = 10**9
    r = -10**9
    for t in range(time+1):
        if t * (time-t) > distance:
            l = min(l, t)
            r = max(r, t)
    print(l, r)
    res *= r-l+1

print(res)