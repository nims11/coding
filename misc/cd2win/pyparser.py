import re
def main():
    N, Q = map(int, raw_input().split())
    tags = {}
    stk = []
    for _ in range(N):
        line = raw_input()
        if line[1] == '/':
            stk.pop()
        else:
            tag, attrstr = line.split(' ', 1)
            attrstr = attrstr.strip()[:-1]
            attrlist = filter(lambda x: len(x)>0, re.split(r'[ =]', attrstr))
            idx = 0
            tags[tag] = {}
            while idx < len(attrlist):
                tags[attrlist[idx]] = attrlist[idx+1]
                idx += 2
            tag = tag[1:]

    for _ in range(Q):
        tag, attr = raw_input().split('~')
        if tag in tags and attr in tags[tag]:
            print tags[tag][attr]
        else:
            print 'Not Found!'
if __name__ == '__main__':
    main()
