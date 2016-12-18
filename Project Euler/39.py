from math import sqrt
d = {}
for a in range(1, 1001):
    for b in range(1, 1001):
        x = sqrt(a*a+b*b)
        if int(x)*int(x) == a*a + b*b:
            p = int(x)+a+b
            if p not in d: d[p] = 0
            d[p] += 1

res = 0
d[0] = 0
for k, v in d.items():
    if v > d[res] and k <= 1000:
        res = k

print res
