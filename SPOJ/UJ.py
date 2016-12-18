while 1:
	ab=raw_input().split(' ')
	ab=[int(ab[x]) for x in (0,1)]
	if ab[0]==0 and ab[1]==0:
		break
	print ab[0]**ab[1]
