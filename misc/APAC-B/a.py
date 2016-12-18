import math
t = input()
for i in range(t):
    n, k = raw_input().split();
    n = int(n)
    k = int(k)
    if math.factorial(2*n)/math.factorial(n)/math.factorial(n)/(n+1) < k:
        print i+1
