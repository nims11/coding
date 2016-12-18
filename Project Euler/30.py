ans = 0
for i in range(100,354295):
	j = i
	sum = 0
	while j>0:
		sum += (j%10)**5
		j /= 10
	if sum == i:
		ans += i
print ans
