from utils import *

lines = readlines('03.in')

res = 0
for x, y in re.findall(r'mul\((\d+),(\d+)\)', '\n'.join(lines)):
    res += int(x)*int(y)
print(res)
