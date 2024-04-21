def rising(array, n):
    sequences = []
    start = 0
    for current in range(n):
        seq = []
        from_ = current
        if array[current] < array[current - 1]:
            start = current
        while from_ >= start:
            seq.insert(0, array[from_])
            from_ -= 1
            sequences.append(seq.copy())
    return sequences
n = int(input())
a = rising([int(i) for i in input().split()], n)
print(len(a))