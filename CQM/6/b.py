#!/usr/bin/python
import re
regex = re.compile(r'((http|https)://'
                   r'([a-zA-Z0-9][a-zA-Z\-0-9]*[a-zA-Z0-9]\.)+'
                   r'[a-zA-Z]{2,}'
                   r'(\/[a-zA-Z0-9\+\&\#\\\/\%\?\=\_\.\-]*)*)($| )')

def main():
	try:
		while True:
			ip = raw_input()
			matches = regex.finditer(ip)
			for i in matches:
				print i.group(1)
			# for i in regex.findall(ip):
			# 	print i[1]
			print
	except EOFError:
		return

if __name__ == '__main__':
	main()