import random
print(10)
for i in range(10):
    N = random.randint(1, 10)
    M = random.randint(1, 10)
    print(N, M)
    s = []
    for i in range(N):
        s.append(['*'] * M)
    s[random.randint(0, N-1)][random.randint(0, M-1)] = '.'
    print('\n'.join([''.join(x) for x in s]))
