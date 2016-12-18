
def getans(n,k):
    x = ''
    for i in range(1, n+1):
        if len(x) > 9:
            return -1
        x += str(i*k)
    return int(x) if len(set(x)) == 9 and len(x) == 9 and '0' not in x else -1
res = 0
for i in range(2, 11):
    print i
    for j in range(1, 100001):
        res = max(res, getans(i, j))
print res
