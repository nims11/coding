def main():
    s = raw_input()
    ss = s
    res = eval(ss)
    for idx in range(len(ss)):
        if idx == 0 or ss[idx-1] == '*':
            for idx2 in range(idx+1, len(ss)):
                if idx2 == len(ss)-1 or ss[idx2+1] == '*':
                    res = max(res, eval(ss[:idx]+'('+ss[idx:idx2+1]+')'+ss[idx2+1:]))
    print res

if __name__ == '__main__':
    main()
