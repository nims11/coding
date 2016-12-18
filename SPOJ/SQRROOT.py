t = int(input())
import math
while t != 0:
	try:
		a = int(input());
	except EOFError:
		break;
	except:
		continue;
	print (int(pow(a,0.5)));
	t -= 1;
