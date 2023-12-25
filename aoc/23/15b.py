from utils import *

lines = readlines('15.in')

def HASH(s):
    res = 0
    for c in s:
        res += ord(c)
        res = res*17%256
    return res

boxes = {}
data = {}
for word in lines[0].split(','):
    if '-' in word:
        label = word[:-1]
        b = HASH(label)
        if b not in boxes or label not in boxes[b]: continue
        boxes[b].remove(label)
        continue
    label, focus = word.split('=')
    b = HASH(label)
    if b not in boxes: boxes[b] = []
    data[label] = int(focus)
    if label in boxes[b]: continue
    boxes[b].append(label)

res = 0
for b, box in boxes.items():
    for i, label in enumerate(box):
        res += (b+1) * (i+1) * (data[label])
print(res)