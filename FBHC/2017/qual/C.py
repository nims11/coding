from __future__ import print_function
from collections import defaultdict
def main():
    t = int(raw_input())
    z = 0
    while t > 0:
        z += 1
        print('Case #%d: ' % z,end='')
        t -= 1
        h, s = map(int, raw_input().split())
        spells = raw_input().split()
        ans = 0
        for spell in spells:
            offset = 0
            times, rest = spell.split('d')
            if '+' in rest:
                sides, offset = rest.split('+')
            elif '-' in rest:
                sides, offset = rest.split('-')
                offset = -int(offset)
            else:
                sides = rest
            times = int(times)
            sides = int(sides)
            offset = int(offset)
            sums = defaultdict(int)
            sums[0] = 1
            for i in range(times):
                sums2 = defaultdict(int)
                for j in range(sides):
                    for su, cnt in sums.items():
                        sums2[su + j + 1] += cnt
                sums = sums2
            cnt = 0
            for su,v in sums.items():
                if su + offset >= h:
                    cnt += v
            ans = max(ans, (cnt / float(sum([v for _, v in sums.items()]))))
        print('%.7f' % ans)

if __name__ == '__main__':
    main()
