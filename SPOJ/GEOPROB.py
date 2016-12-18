#!/usr/bin/python
t = input()
while t>0:
	b,c,d = tuple(raw_input().split())
	print 2*int(c) - (int(b)+int(d))
	t -= 1
