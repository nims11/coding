res = 1
cur = 1
curIdx = 0
foo = [10**i for i in range(7)]
for req in foo:
    while True:
        if curIdx + len(str(cur)) >= req:
            break
        curIdx += len(str(cur))
        cur += 1
    res *= int(str(cur)[req-curIdx-1])

print res
