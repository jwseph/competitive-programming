s = open('aoc/22/06.in').read().strip()

for i in range(len(s)):
    if len(set(s[i-4:i])) == 4:
        print(i)
        break