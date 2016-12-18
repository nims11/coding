def main():
    t = input()
    while t != 0:
        t -= 1
        n, m = map(int, raw_input().split())
        words = raw_input().split()
        dic = {}
        for w in words:
            dic[w] = 0
        for i in range(m):
            w = raw_input().split()[1:]
            for ww in w:
                if ww in dic:
                    dic[ww] = 1
        for word in words:
            print ("YES" if dic[word] == 1 else "NO"),
        print
main()
