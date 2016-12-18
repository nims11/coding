import random
N = 100000
print N
for i in range(N):
    n = random.randint(1, 10)
    arr = [random.randint(1, 10) for i in range(n)]
    m = random.randint(1, 10)
    length = n
    for i in range(m):
        length += length - 1
    l = random.randint(1, length);
    r = random.randint(1, length);
    if l > r:
        l, r = r, l
    print n, m, l, r
    print ' '.join(map(str, arr))
