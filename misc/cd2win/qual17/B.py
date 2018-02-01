T = int(input())
candidates = []

for a in range(1, 1001):
    for b in range(1001):
        candidates.append(int('4' * a) * (10 ** b))

candidates.sort()

while T > 0:
    T -= 1
    X = int(input())
    for candidate in candidates:
        if candidate % X == 0:
            print("YES")
            break
    else:
        print("NO")
