t = input()
while t!=0:
	a, b = tuple(raw_input().split())
	n = int(a)
	n2 = n
	p = int(b)
	ans = 1
	while n>0:
		foo = n%p
		ans *= foo+1
		n/=p
	print n2+1-ans
	t -= 1
