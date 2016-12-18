import re
label_re = re.compile(r'^ *([a-zA-Z]*):$')
goto_re = re.compile(r'^ *goto ([a-zA-Z]*);$')
def main():
	t = input()
	for z in xrange(1, t+1):
		ans = 0
		n = input()
		labels = {}
		for i in xrange(n):
			line = raw_input()
			x = label_re.match(line)
			if x != None:
				labels[x.group(1)] = i
			else:
				x = goto_re.match(line)
				if x != None: 
					y = labels[x.group(1)]
					ans += i - y - 1
		print 'Scenario #%d: %d' % (z, ans)

if __name__ == '__main__':
	main()
