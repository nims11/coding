#!/usr/bin/python
t = input()
i = 1
def foobar(main_set, str1):
	n = 0
	bar = str1.split('/')
	qwe = range(len(bar))
	curr = ''
	for idx in qwe:
		if bar[idx]=='':
			curr += '/'
		else:
			curr += bar[idx]
			if curr in main_set:
				pass
			else:
				n+=1
				main_set.add(curr)
	return n
while i<= t:
	n,m = raw_input().split()
	n = int(n)
	m = int(m)
	s = set([])
	for x in range(n):
		str1 = raw_input()
		foobar(s, str1)
	ans = 0
	for x in range(m):
		str1 = raw_input()
		ans += foobar(s, str1)
	print "Case #%d:"%i, ans
	i+=1
