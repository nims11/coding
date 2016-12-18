import random
T = 10000
print(T)
for _ in range(T):
    N = random.randint(2, 10)
    print(N)
    for i in range(N):
        print(random.randint(0, 10), random.randint(0, 10))
