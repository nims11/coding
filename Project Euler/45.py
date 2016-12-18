n = 144
import math
def solve(a, b, c):
    D = b*b-4*a*c
    if D < 0:
        return 0
    x = math.sqrt(D)
    x = int(x)
    if x*x != D:
        return -1
    if((-b + x) % (2*a) != 0):
        return -1
    x = (-b+x)/(2*a)
    if x < 0:
        return -1
    return x
while True:
    H = n*(2*n-1)
    Tn = solve(1, 1, -2*H)
    Pn = solve(3, -1, -2*H)
    if Tn != -1 and Pn != -1:
        print H
        break
    n+=1
