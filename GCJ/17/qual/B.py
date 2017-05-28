t = int(input())
def getans(N):
    l = len(N)
    for i in range(l-1):
        if N[i] > N[i+1]:
            N[i] -= 1
            i+=1
            while i < l:
                N[i] = 9
                i += 1
            return getans(N)
    return N

for z in range(t):
    print("Case #%d: " % (z+1), end="")
    N = list(map(int, input()))
    ans = getans(N)
    print(int(''.join(map(str, N))))
