# using standard library bigfloat
from bigfloat import *
T = int(raw_input())
z = 0
while T != 0:
    z += 1
    n, m = map(int, raw_input().split())
    arr = map(int, raw_input().split())
    for i in range(1, len(arr)):
        arr[i] = arr[i-1]*arr[i]
    print "Case #%d:" % z
    for i in range(m):
        l, r = map(int, raw_input().split())
        prod = arr[r]
        if l != 0:
            prod /= arr[l-1]
        res = BigFloat.exact(prod)**BigFloat.exact(float(1)/(r-l+1))

        print BigFloat(res, context=RoundTowardPositive+precision(100))
    T -= 1
