def mex(arr):
    for i in range(1000):
        if i not in arr:
            return i

def get_partitions(arr):
    if len(arr) == 1:
        return [[arr]]
    ret = []
    partitions = get_partitions(arr[:-1])
    for partition in partitions:
        print(partition)
        ret.append(partition + [[arr[-1]]])
        partition[-1] += [arr[-1]]
        ret.append(partition)
    return ret

def invalid(arr, k):
    partitions = get_partitions(arr)
    ret = 0
    for partition in partitions:
        if max((mex(arr) for arr in partition)) > k:
            ret += 1
