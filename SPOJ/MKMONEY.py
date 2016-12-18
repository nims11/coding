#!/usr/bin/python
def main():
	cc = 1
	while 1:
		try:
			inp = raw_input().split(' ')
			P, I, C = float(inp[0]), float(inp[1]), int(inp[2])
			if C == 0:
				break
			II = I
			I /= 100
			I /= C
			ans = P
			for i in range(C):
				inte = ans*I
				inte = float(int(inte*100))/100
				ans += inte
			
			print 'Case %d. $%.2f at %.2f%s APR compounded %d times yields $%.2f' % (cc, P, II, '%', C, ans)
			cc += 1
		except EOFError:
			break
		#except:
			continue

if __name__ == '__main__':
	main()

