#!/usr/bin/python
def getlen(letters, n):
	cur = 0
	res = 1
	tmp = len(letters)
	prev_cur = 0
	while cur < n:
		prev_cur = cur
		cur += tmp
		res += 1
		tmp *= len(letters)
	return res-1, n-prev_cur

def getans(letters, n, length):
	if length == 0:
		return ''
	cur = 0
	increase = len(letters)**(length-1)
	# print length, increase, n
	# subprocess.call('sleep 1', shell=True)
	for v in letters:
		cur += increase
		# print cur, n
		if cur >= n:
			return v+getans(letters, n-cur+increase, length-1)


def solve(c):
	letters, n = raw_input().split()
	n = int(n)
	length, newN = getlen(letters, n)
	print 'Case #%d: %s' % (c, getans(letters, newN, length))

if __name__ == '__main__':
	t = input()
	z = 1
	while t != 0:
		solve(z)
		t -= 1
		z += 1