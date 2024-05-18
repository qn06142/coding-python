def fill_cells(n, a):
    res = 0
    i = 0
    while i < n:
        v = a[i]
        j = i
        while j < n and a[j] == v:
            j += 1
        res += 1
        i = j
    return res

T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    print(fill_cells(n, a))