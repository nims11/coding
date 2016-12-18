import random
n = random.randint(3, 8);
arr = []
for i in range(n):
    arr += [random.randint(1, 3)]

arr = list(map(str, arr))
with open('in1', 'w') as f:
    f.write(str(n)+'\n')
    ii = random.randint(0, n-1)
    f.write(' '.join(arr[ii:] + arr[:ii]) + '\n')

with open('in2', 'w') as f:
    f.write(str(n)+'\n')
    ii = random.randint(0, n-1)
    f.write(' '.join(arr[ii:] + arr[:ii]) + '\n')
