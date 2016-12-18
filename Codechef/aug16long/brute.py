def merge(arr):
    ret = []
    cur = []
    for t in arr:
        if len(cur) == 0 or cur[-1] == t-1:
            cur.append(t)
        else:
            ret.append((cur[0], cur[-1]))
            cur = [t]
    if len(cur) != 0:
        ret.append((cur[0], cur[-1]))
    return ret

t = int(input())
iii = 0
while t != 0:
    print(iii)
    n = int(input())
    arr = []
    for i in range(n):
        h, m = map(int, input().split())
        arr.append((h, m))
    if iii == 269:
        print(arr)
    valid = []
    for time in range(300):
        isval = True
        for i in range(1, len(arr)-1):
            if arr[i-1][0] < arr[i][0] > arr[i+1][0] or arr[i-1][0] > arr[i][0] < arr[i+1][0]:
                pass
            else:
                isval = False
                break
        if len(arr) == 2:
            isval = (arr[0][0] != arr[1][0])
        if isval:
            valid.append(time);
        for idx, (h,m) in enumerate(arr):
            arr[idx] = (h+m, m)

    intervals = merge(valid)
    print(len(intervals))
    for x,y in intervals:
        print(x, ("Inf" if y == 299 else y))
    t -= 1
    iii += 1
