primes=[];
import math;
def isPrime(n):
	if n==1:return False;
	limit=int(math.sqrt(n));
	for i in primes:
		if i>limit:
			break;
		if n%i==0:
			return False;

	return True;

def generate_prime(n):
	primes.append(2);
	for i in range(3,n+1):
		if isPrime(i):
			primes.append(i);

generate_prime(10000);
while 1:
	try:
	   n=int(raw_input());
	except EOFError:
		break;
	except:
		continue;
	b=[];
	for i in primes:
		count=0;
		d=i;
		while n/d:
			count+=n/d;
			d*=i;

		if count>0:
			b.append((i,count));

	for i in range(0,len(b)-1):
		print "{0}^{1} *".format(b[i][0],b[i][1]),

	print "{0}^{1}".format(b[len(b)-1][0],b[len(b)-1][1]);
