import random
print 10000
for i in range(10000):
    n = random.randint(1, 100)
    print n
    print ''.join([random.choice(['(', ')']) for i in range(n)])
    print ' '.join([str(random.randint(100000000, 1000000000)) for i in range(n)])
