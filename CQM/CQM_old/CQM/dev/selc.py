#!/usr/bin/python

def getans(lst, flag):
	if len(lst) == 1:
		return lst[0]
	if flag == 1:
		return getans(lst[0::2], -1) and getans(lst[1::2], -1)
	else:
		return getans(lst[0::2], 1) or getans(lst[1::2], 1)

while True:
	try:
		case = raw_input()
		case = case.split()
		lst = []
		avg = 0
		case2 = case[1:]
		for i in case2:
			avg += int(i)

		for i in case2:
			if avg <= len(case2)*int(i):
				lst.append(True)
			else:
				lst.append(False)
		a = getans(lst, -1)
		if a:
			print case[0]+' '
		else:
			if case[0][0] == 'H':
				print 'Cat '
			else:
				print 'Hacky '
	except:
		break
