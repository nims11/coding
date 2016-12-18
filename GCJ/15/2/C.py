import sys
T = int(raw_input())

for z in range(1, T+1):
    N = int(raw_input())
    eng = raw_input()
    fre = raw_input()
    eword, fword = set(), set()
    for w in eng.split():
        eword.add(w)
    for w in fre.split():
        fword.add(w)
    sents = []
    for i in range(N-2):
        sents.append(set(raw_input().split()))
    res = -1
    for i in range(1<<(N-2)):
        e = eword.copy()
        f=  fword.copy()
        for j in range(N-2):
            if i&(1<<j) > 0:
                for w in sents[j]:
                    e.add(w)
            else:
                for w in sents[j]:
                    f.add(w)
        res2 = len(e.intersection(f))
        if res == -1:
            res = res2
        else:
            res = min(res, res2)
    print 'Case #%d: %d' % (z, res)
    sys.stdout.flush()
