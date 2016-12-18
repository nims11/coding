T = input()
Z = 1
def ans(x):
    print "Case #%d: %s" % (Z, str(x))

while Z <= T:
    N = input()
    n = N;
    if N == 0:
        ans('INSOMNIA')
    else:
        N = 0
        seen = set()
        while len(seen) != 10:
            N += n;
            print N, set(seen)
            for dig in str(N):
                seen.add(dig)
        ans(N)
    Z += 1
