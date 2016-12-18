while True:
    vals = raw_input().split();
    values = [int(vals[0], i) for i in range(2, 11)]
    vals = map(int, vals)
    for i in range(1, 10):
        if values[i-1] % vals[i] != 0 or vals[i] == values[i-1]:
            print vals, values[i-1]
            break
