#!/usr/bin/python
import sys
x = ''
for line in sys.stdin:
	x += line
raise Exception(x)
forbid = []
ans = -1
def check(n):
	for x in str(n):
		if int(x) in forbid:
			return False
	return True

def f(res, n, off):
	if check(res) and res != 0:
		return res
	ret = -1
	for i in xrange(10):
		res2 = res+n*off*i
		if not (res == 0 and off == 1 and i == 0) and (res2//off)%10 not in forbid:
			x = f(res2, n, off*10)
			if x != -1:
				return x
			if ret == -1:
				ret = x
			else:
				ret = min(ret, x)


	return ret
def main():
	global forbid
	t = input()
	while t != 0:
		t -= 1
		n = input()
		forbid = map(int, raw_input().split())
		try:
			res = f(0, n, 1)
			print res
		except:
			print 'Naa Ho Paayega'
		

if __name__ == '__main__':
	main()