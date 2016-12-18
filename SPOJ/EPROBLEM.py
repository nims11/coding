import math
def C(n,a=''):
	if n==0:return '0'
	while n:x=int(math.log(n,2));n-=1<<x;a+="2+" if x==1 else "2("+C(x)+")+"
	return a[:-1]
while 1:
 try:i=input();print str(i)+'='+C(i)
 except:break