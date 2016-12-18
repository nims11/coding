
def sqrt(x):
    st = int(x ** 0.5)
    while st*st > x:
        st -= 1
    while (st+1)*(st+1) <= x:
        st += 1

    for precision in range(8):
        prev = 0
        st *= 10
        x *= 100
        for i in range(1, 10):
            if (st+i)*(st+i) <= x:
                prev = i
            else: break
        st += prev
    return st

def sqrts(x):
    y = sqrt(x)
    y = str(y)
    return (y[:-12] if len(y) > 12 else '0') + '.' + ('0'*max(0, 12-len(y))) + y[-12:]

def main():
    T = int(raw_input())
    while T > 0:
        T -= 1
        H, S = map(int, raw_input().split())
        D = H*H*H*H - 16*S*S
        if D < 0:
            print -1
        else:
            if H*H*H*H <= D:
                print -1
            else:
                D = sqrt(D)
                ans1 = (H*H*100000000 + D)//2
                ans2 = (H*H*100000000 - D)//2
                if ans1 > ans2:
                    ans1, ans2 = ans2, ans1
                print '%s %s %.12lf' % (sqrts(ans1), sqrts(ans2), H)

main()

