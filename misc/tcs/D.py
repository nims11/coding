import sys
import math
input = []
for line in sys.stdin:
    input.append(line.strip())
input.reverse()
t = int(input.pop())
res = []
def convert(x):
    try:
        x = int(x)
    except:
        try:
            x = float(x)
        except:
            pass
    return x

while t > 0:
    op = input.pop()
    c1 = int(input.pop())
    c2 = int(input.pop())
    c1 -= 1
    c2 -= 1
    rows = []
    while True:
        row = input.pop()
        if row == '-1':
            break
        compo = row.split()
        rows.append(compo)

    if op != 'Invert':
        group = {}
        for row in rows:
            grp = convert(row[c1])
            agg = convert(row[c2])

            if grp not in group: group[grp] = [0, 0]
            group[grp][1] += 1
            if op != "Count":
                group[grp][0] += agg

        local_res = []
        for grp, (sum, cnt) in group.items():
            if op == 'Sum': agg = math.ceil(sum)
            elif op == 'Average': agg = math.ceil(sum/cnt)
            elif op == 'Count': agg = cnt
            local_res.append((grp, agg))
        local_res.sort(key=lambda x: (x[0]))
        local_res = [' '.join(map(str,x)) for x in local_res]
        res += local_res
    else:
        col_headers = list(set([convert(row[0]) for row in rows]))
        col_headers.sort(key=lambda x: convert(x))
        col_headers = {row: i for i,row in enumerate(col_headers)}
        group = {}
        for row in rows:
            grp = convert(row[c1])
            agg = row[c2]
            if grp not in group: group[grp] = ['#' for i in range(len(col_headers))]
            group[grp][col_headers[convert(row[0])]] = str(agg)

        local_res = []
        for grp, arr in group.items():
            local_res.append((grp, ' '.join(arr)))
        local_res.sort(key=lambda x: (x[0]))
        local_res = [' '.join(map(str,x)) for x in local_res]
        res += local_res
    t -= 1

sys.stdout.write('\n'.join(res))
