
def main():
    s = raw_input()
    if len(s) < 4:
        x = 1
        for i in range(1, 7):
            x *= i
            if x == int(s):
                print i
                return
    else:
        x = 1
        l = len(s)
        for i in range(1, 26000):
            x *= i
            print i
            if l == len(str(x)):
                print i
                return
if __name__ == '__main__':
    main()
