#!/usr/bin/python2.7
passes = []
from random import seed, randint, choice
from sys import stdout
import string
def randStr():
	return ''.join(choice(string.lowercase) for x in xrange(randint(8,12)))

def main():
	T,N,H = map(int, raw_input().split())
	for i in xrange(N):
		passes.append(randStr())
	for i in xrange(T):
		for j in xrange(N):
			print randStr()
		stdout.flush()
		x = input()

if __name__ == '__main__':
	main()
