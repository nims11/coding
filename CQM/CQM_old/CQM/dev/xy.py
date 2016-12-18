#!/usr/bin/python
import math
primes = []
def isPrime(n):
	if n==1:
		return False
	length = len(primes)
	lt = int(math.sqrt(n))
	i = 0
	while i<length and primes[i]<=lt:
		if n%primes[i] == 0:
			return False
		i += 1
	return True
def generatePrimes(n):
	global primes
	primes.append(2)
	i = 3
	while i<=n:
		if isPrime(i):
			primes.append(i)
		i+=2


def getans(n):
	foo = range(len(primes))
	ans = 1
	for i in foo:
		if primes[i]>n:
			break
		zz = 0
		bar = primes[i]
		while n/bar != 0:
			zz += n/bar
			bar *= primes[i]
		ans = ans*(2*zz + 1)
	print ans

generatePrimes(10000)
t  = input()
i = 0
while i<t:
	n = input()
	getans(n)
	i +=1
