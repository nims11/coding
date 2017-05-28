from collections import defaultdict
t = int(input())
for z in range(t):
    print("Case #%d: " % (z+1), end="")
    N, K = list(map(int, input().split()))
    state = {N: 1}
    cur = 1
    while cur < K:
        new_state = defaultdict(int)
        for k in state:
            if k % 2 == 0:
                new_state[k//2] += state[k]
                new_state[k//2-1] += state[k]
            else:
                new_state[(k-1)//2] += 2 * state[k]
        state = new_state
        cur += sum([v for k, v in state.items()])
        if cur >= K:
            K -= cur - sum([v for k, v in state.items()])

    max_key = max(state.keys())
    min_key = min(state.keys())
    val = max_key if state[max_key] >= K else min_key
    val -= 1
    a = val // 2
    b = val - a
    print(max(a, b), min(a, b))
