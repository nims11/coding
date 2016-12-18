x = []
for m in range(1, 7):
	for n in range(1+m, 9):
		x.append((n, m))

print len(x)
for x, y in x:
	print x, x+y
