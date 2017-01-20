from collections import defaultdict
import string
def main():
    tokens = raw_input().split(',')
    d = defaultdict(list)
    stk = []
    for tok in tokens:
        if tok[0] in string.ascii_letters:
            d[len(stk)].append(tok)
            if len(stk) > 0:
                stk[-1] -= 1
        else:
            stk.append(int(tok))
            while len(stk) > 0 and stk[-1] == 0:
                stk.pop()
    cur = 0
    out = []
    while cur in d:
        out.append(' '.join(d[cur]))
        cur += 1
    print cur
    print '\n'.join(out)

if __name__ == '__main__':
    main()
