op = []
count = 5
r = range(-2, 3)

def f(n, l):
	if n == count:
		op.append(l)
	else:
		for i in r:
			f(n+1, l+[i])

f(0, [])
print len(op)
for i in op:
	print count
	for j in i:
		print j,
	print
