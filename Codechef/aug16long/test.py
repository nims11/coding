import random
print(6)
i = 6
xxx = set()
while i > 0:
    x, y = random.randint(-5, 5), random.randint(-5, 5)
    if x != 0 and y != 0 and (x, y) not in xxx:
        print(x, y)
        xxx.add((x, y))
        i -= 1
