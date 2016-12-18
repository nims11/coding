import re
local1 = re.compile(r'^\w[a-zA-Z0-9\._-]*\w$')
local2 = re.compile(r'^\w$')
domain1 = re.compile(r'^[a-zA-Z]{2,}$')
domain2 = re.compile(r'^\w[a-zA-Z0-9-]*\w$')
def local_check(str1):
	if local2.match(str1)!=None or local1.match(str1)!=None:
		asa = str1.split('.')
		for ass in asa:
			if ass == '':
				return False
		return True
	else:
		return False

def local_check2(str1):
	if local2.match(str1)!=None or domain2.match(str1)!=None:
		return True
	else:
		return False

def domain_check(str1):
	foo = str1.split('.')
	d = range(len(foo)-1)
	for i in d:
		if foo[i] == '':
			return False
		if not local_check2(foo[i]):
			return False
	if domain1.match(foo[len(foo)-1])==None:
		return False
	return True
while True:
	try:
		email = raw_input()
		foo = email.split('@')
		if len(foo)!=2:
			print 'Invalid'
			continue
		else:
			if local_check(foo[0]) and domain_check(foo[1]):
				print 'Valid'
			else:
				print 'Invalid'
	except EOFError:
		break
