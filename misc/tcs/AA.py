import sys
input = []
for line in sys.stdin:
    input.append(line.strip())

fname1 = input[0]
fname2 = input[1]

user_id_2_name = {}
with open(fname2) as f:
    for line in f:
        user_id, user_name, email = line.strip().split(',')
        user_id_2_name[user_id] = user_name

res = []
with open(fname1) as f:
    for line in f:
        contest_id, problem_id, user_id, sub_id, lang, prob_name, status, t1, t2, t3 = line.strip().split(',')
        user_name = user_id_2_name.get(user_id, None)
        if user_name == None:
            continue
        res.append((user_id, user_name, problem_id, prob_name, sub_id, lang, status))

res.sort(key=lambda x: (x[0], x[-1]))
sys.stdout.write('\n'.join(','.join(x) for x in res))
