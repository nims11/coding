#!/usr/bin/python2.7
def getres(r,t,mid):
	return 2*mid*r + mid*(2*mid-1)
c = 0
T = int(input())
while T>0:
	c += 1
	x = raw_input().split(' ')
	r = int(x[0])
	t = int(x[1])
	st = 0
	e = 1000000000
	ans = 0
	while(st<=e):
		mid = (st+e)/2
		res = getres(r,t,mid)
		if res<=t:
			st = mid+1
			ans = mid
		else:
			e = mid-1
	print 'Case #%d: %d' % (c, ans)
	T -= 1
