def find_replacement_positions(a: int, b: int):
    a_str = str(a)
    b_str = str(b)
    n = len(a_str)
    m = len(b_str)
    pref = [0 for i in range(0, n + 5)]
    for i in range(1, n + 1):
        pref[i] = pref[i - 1] + int(a_str[i -1])
    #print(pref)
    suffsize = prefsize = 0
    while prefsize < min(n, m) and a_str[prefsize] == b_str[prefsize]: prefsize += 1
    while suffsize < min(n, m) and a_str[n - 1 - suffsize] == b_str[m - 1 - suffsize]: suffsize += 1
    it = n - 1
    pos = [0] * n
    for i in range(n - 1, -1, -1):
        pos[i] = it
        if a_str[i] != '0':  
            it = i
    for i in range(prefsize + 1):
        for j in range(max(pos[i], n - suffsize), n + 1):
            if j - i >= 1000: break;
            digit_sum = pref[j] - pref[i];
            #print(a_str[i:j], i, j)
            new_number = a_str[:i] + str(digit_sum) + a_str[j:]
            if new_number == b_str:
                if i + 1 >= j:
                    return 1, 1;
                return (i + 1, j)


a = int(input())
b = int(input())
positions = find_replacement_positions(a, b)
print(*positions)