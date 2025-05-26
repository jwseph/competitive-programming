lines = open('aoc/22/07.in').readlines()
res = 0
s = []
size = None
for line in lines:
    if line.startswith('$ cd ..'):
        if s[-1][1] <= 10**5:
            res += s[-1][1]
        s.pop()
        continue
    if line.startswith('$ cd'):
        _, _, name = line.split()
        s.append([name, 0])
        continue
    x = line.split()
    if x[0].isdigit():
        for obj in s:
            obj[1] += int(x[0])
print(res)
print(s[0][1])
# 7870454

# 11:27