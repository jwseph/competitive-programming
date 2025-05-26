from utils import *

lines = readlines('03.in')
s = "do()" + '\n'.join(lines)
good = 'do()'
bad = "don't()"

res = 0
for x, y in re.findall(r'mul\((\d+),(\d+)\)', s):
    sub = f'mul({x},{y})'
    if sub in s:
        i = s.index(sub)
        s = s.replace(sub, '')
        g = s[:i].rfind(good)
        b = s[:i].rfind(bad)
        if g >= b: res += int(x)*int(y)
print(res)
