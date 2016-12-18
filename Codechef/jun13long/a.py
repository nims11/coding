from random import choice
t = 20
print t
lt = range(2, 10)
s_c = ['0','1']
for i in range(t):
	r = choice(lt)
	c = choice(lt)
	print r, c
	for j in range(r):
		s=""
		for k in range(c):
			s += choice(s_c)
		print s

