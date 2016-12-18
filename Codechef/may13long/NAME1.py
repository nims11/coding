def f():
	t = input()
	while t!=0:
		t -= 1
		A,B = raw_input().split()
		AB = A+B
		n = input()
		C = ''
		for i in range(n):
			C += raw_input()
		foo1 = [0 for i in xrange(26)]
		foo2 = [0 for i in xrange(26)]
		for x in AB:
			foo1[ord(x)-ord('a')] += 1
		for x in C:
			foo2[ord(x)-ord('a')] += 1
		flag = True
		for idx in range(26):
			if foo2[idx]>foo1[idx]:
				flag = False
				break
		if flag:
			print 'YES'
		else:
			print 'NO'

if __name__ == '__main__':
	f()
