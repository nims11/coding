#!/usr/bin/python
C = [[(1 if y == 0 or y == x else 0) for y in xrange(1001)] for x in xrange(1001)]
for i in xrange(1001):
	for j in xrange(1, i):
		C[i][j] = C[i-1][j-1] + C[i-1][j]

def main():
	t = input()
	while t != 0:
		t -= 1
		delim = raw_input()
		N, S, M, B = map(int, raw_input().strip().split(delim))
		#print N, S, M, B
		res = 0
		# print C[S][M]*C[N-M][B-M]
		for i in xrange(M, S+1):
			if B-i < 0:
				break
			res += C[S][i]*C[N-S][B-i]
		print res

if __name__ == '__main__':
	main()