def rev(n):
	"""reverses number"""
	n_rev = 0
	while n > 0:
		n_rev = n_rev*10 + n%10
		n = n/10
	return n_rev
t = int(raw_input())
for i in range(t):
	ab = raw_input().split(' ')
	ab[0] = rev(int(ab[0]))
	ab[1] = rev(int(ab[1]))
	res = ab[0] + ab[1]
	res = rev(res)
	print res


