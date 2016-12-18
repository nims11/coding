sieve = [0 for i in range(10000)]
primes = [2]
for i in range(3, 10000, 2):
    if sieve[i] == 0:
        primes.append(i)
        for j in range(i*i, 10000, i):
            sieve[j] = 1

primes = set(primes)
for i in range(1000, 10000):
    for d in range(1000, 5000):
        i1, i2, i3 = i, i+d, i+2*d
        if i1 in primes and i2 in primes and i3 in primes:
            if i2 < 10000 and i3 < 10000:
                i1 = list(str(i1))
                i2 = list(str(i2))
                i3 = list(str(i3))
                i1.sort()
                i2.sort()
                i3.sort()
                if ''.join(i1) == ''.join(i2) == ''.join(i3):
                    print i, i+d, i+2*d
