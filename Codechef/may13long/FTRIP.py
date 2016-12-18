def f():
	CC = [[0]*1001 for x in xrange(1001)]
	for i in range(1001):
		CC[i][0] = 1
	for i in range(1, 1001):
		for j in range(1, i+1):
			CC[i][j] = CC[i-1][j-1] + CC[i-1][j]
	t = input()
	while t!=0:
		t -= 1
		s,n,m,k = raw_input().split()
		s = int(s);n = int(n); m = int(m); k = int(k)
		num = 0
		for j in range(k, min((n,m))):
			#print m-1, j, s-m, n-1-j
			num += CC[m-1][j]*CC[s-m][n-1-j]
		num = num/float(CC[s-1][n-1])
		print '%.6f' % num

if __name__ == '__main__':
	f()
