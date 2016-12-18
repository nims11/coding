import sys
from collections import defaultdict
import math
fname = sys.stdin.read().strip()
input = []
with open(fname) as f:
    for line in f:
        if len(line.strip()) == 0:
            continue
        input+=(line.strip().split())
input.reverse()
t = int(input.pop())
res = []
while t > 0:
    X = int(input.pop())
    Y = int(input.pop())
    I = int(input.pop())
    C = int(input.pop())
    if I == 0:
        I = 1
    N = int(input.pop())
    if C == 0:
        continue
    parking_lots = defaultdict(int)
    cars = {}
    res.append(str((X//I+1) * (Y//I+1)))

    while N > 0:
        op = input.pop()
        if op == 'P':
            x, y = int(input.pop()), int(input.pop())
            _id = input.pop().lower()
            closest_x = I * (x//I)
            if closest_x + I <= X and closest_x + I - x < x - closest_x:
                closest_x = closest_x + I
            closest_y = I * (y//I)
            if closest_y + I <= Y and closest_y + I - y < y - closest_y:
                closest_y = closest_y + I
            parking_lots[(closest_x, closest_y)] += 1
            tot = parking_lots[(closest_x, closest_y)]
            floor = (tot-1)// C
            cars[_id] = ((closest_x, closest_y), floor, (tot-1) % C)
        else:
            _id = input.pop().lower()
            if _id not in cars:
                continue
            (x, y), floor, slot = cars[_id]
            res.append(' '.join(map(str, [x%10, y%10, floor%10, (slot+1)%10])))
        N -= 1
    t -= 1

sys.stdout.write('\n'.join(res))
