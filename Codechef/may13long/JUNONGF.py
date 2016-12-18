mod = 1000000007
def POW(r, n):
	ans = 1
	while n>0:
		if n%2 == 1:
			ans = (ans*r)%mod
		n /= 2
		r = (r*r)%mod
	return ans

def main():
	T = input()
	while T!=0:
		T -= 1
		V, N = map(int, raw_input().split())
		print V
		P, Q = [0,0], [0,0]
		P[0], P[1], A0, B0, C0, M0 = map(int, raw_input().split())
		Q[0], Q[1], A1, B1, C1, M1 = map(int, raw_input().split())
		for i in xrange(2, N):
			P.append((((((A0*A0)%M0)*P[i-1])%M0 + (B0*P[i-2])%M0)%M0 + C0)%M0)
			Q.append((((((A1*A1)%M1)*Q[i-1])%M1 + (B1*Q[i-2])%M1)%M1 + C1)%M1)
		L = []
		for i in xrange(N):
			L.append(P[i]*M1+Q[i]+1)
		
		foo = 1
		x = 0
		for i in xrange(N):
			if L[i] == 1: x = 1
			foo = (((L[i]-1)%(mod-1))*foo)%(mod-1)
		if V%mod == 0 and x != 0:
			print 1
		elif V%mod == 0:
			print 0
		else:
			print POW(V%mod, foo)


if __name__ == '__main__':
	main()
