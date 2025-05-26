s = open('aoc/22/06.in').read().strip()

for i in range(len(s)):
    if len(set(s[i-14:i])) == 14:
        print(i)
        break