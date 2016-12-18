def is_subseq(str1, str2):
	if len(str1)<len(str2):
		return False
	idx1, idx2, len1, len2 = 0, 0, len(str1), len(str2)
	while idx1<len1:
		if str1[idx1] == str2[idx2]:
			idx2 += 1
		idx1 += 1
		if idx2 == len2:
			return True
	return False

def f():
	t = input()
	while t!=0:
		t -= 1
		n1, n2 = raw_input().split()
		if is_subseq(n1, n2) or is_subseq(n2, n1):
			print 'YES'
		else:
			print 'NO'


if __name__ == '__main__':
	f()
