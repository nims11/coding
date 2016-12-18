#!/usr/bin/python

import random

print """6
1 1 1 0 2 1"""
Q = 50
print Q
while Q != 0:
    op = random.choice(['I','O','E','M'])
    Q -= 1
    l = random.randint(1,6)
    r = random.randint(1,6)
    if l > r:
        l, r = r, l
    print op, l, r
