pent = dict([(n*(3*n-1), n) for n in range(1, 10000)])
D = 1000000000000
for k in pent.keys():
    for j in pent.keys():
        if k!=j:
            if k+j in pent and abs(k-j) in pent:
                D = min(D, abs(k-j))
print D

