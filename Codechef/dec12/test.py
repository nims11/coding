from math import log
from math import exp

def log_fac(n):
	sum = 0
	for i in range(2,n+1): sum += log(i)
	return sum

def log_binomial(n,k): return (log_fac(n)-log_fac(k)-log_fac(n-k))

print int(exp(log_binomial(80, 40)))%1000000009
