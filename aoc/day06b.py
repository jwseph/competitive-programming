lines = open('aoc/day06.in').read().splitlines()
times = lines[0].split()[1:]
distances = lines[1].split()[1:]

times = [''.join(times)]
distances = [''.join(distances)]

for time, distance in zip(times, distances):
    time = int(time)
    distance = int(distance)

    M = 23344933

    l, r = 0, M
    while l < r:
        h = (l+r)//2
        if h*(time-h) > distance: r = h
        else: l = h+1

    res_l = l
    print('part1')

    l, r = M, time
    while l < r:
        h = (l+r)//2
        if h*(time-h) > distance: l = h
        else: r = h-1

    res_r = r

print(res_r-res_l+1)