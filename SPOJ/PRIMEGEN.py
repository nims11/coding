primes = []
import math
def isPrime(n):
	if n == 1:
		return False
	i = 0
	limit = int(pow(n,0.5))
	i_limit = len(primes)
	while primes[i] <= limit and i<i_limit:
		if n % primes[i] == 0:
			return False;
		i = i + 1
	return True
def generate_primes(limit):
	primes.append(2)
	for i in range(3,limit+1):
		if isPrime(i):
			primes.append(i)

def main():
	t = int(raw_input())
	generate_primes(int(pow(1000000000,0.5)));
	while t>0:
		mn = raw_input().split(' ')
		for i in range(int(mn[0]), int(mn[1])+1):
			if isPrime(i):
				print i
		t = t - 1
		print


if __name__ == '__main__':
	main()
