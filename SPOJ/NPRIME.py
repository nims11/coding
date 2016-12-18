p=[2];n=range(3,1299710,2);c=0
for m in n:
 if m!=0:
	p+=[n[c]]
	for i in range(c+m,len(n),m):n[i]=0
 c+=1
while 1:
	try:print p[input()-1]
	except:break