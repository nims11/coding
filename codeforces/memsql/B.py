from math import sqrt
res = []
A = 2
def solve(a, b, c):
	D2 = b*b - 4*a*c
	if D2<0: return -1
	D = int(sqrt(D2))
	while D*D<D2:
		D+=1
	while D*D>D2:
		D-=1
	if D*D != D2:
		return -1
	num1 = -b + D
	num2 = -b - D
	if num1%2 == 0:
		x = num1/2
		if x > 0 and x%2 == 1:
			res.append(A*x/2)
	if num2%2 == 0:
		x = num2/2
		if x > 0 and x%2 == 1:
			res.append(A*x/2)

def main():
	global A, res
	n = input()
	n = -2*n
	for i in xrange(1, 65):
		solve(1, A-3, n)
		A *=  2
	if len(res) == 0:
		print -1
	else:
		res.sort()
		prev = -1
		for i in res:
			if i != prev:
				print i
			prev = i
if __name__ == '__main__':
	main()

