#!/usr/bin/python

N, M, R = map(int, raw_input().split())

res = 1
for i in range(1, N+1):
    res = res * (i**i)
for i in range(1, R+1):
    res = res / (i**i)
for i in range(1, N-R+1):
    res = res / (i**i)

print res%M
