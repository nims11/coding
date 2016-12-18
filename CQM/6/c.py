#!/usr/bin/python

def main():
	try:
		while True:
			ip, n = raw_input().split();
			n = int(n)
			occ = []
			for i in xrange(len(ip)):
				if ip[i] == 'Y':
					occ.append(i)
			res = 0
			l = len(occ)
			tot = len(ip)
			for i in xrange(l-n+1):
				frnt = 0
				if i != 0:
					frnt = occ[i-1]+1
				bck = tot-1
				if i != l-n:
					bck = occ[i+n]-1
				res += (occ[i]-frnt+1)*(bck-occ[i+n-1]+1)
			print res
	except EOFError:
		return

if __name__ == '__main__':
	main()