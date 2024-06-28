n, m = (int(i) for i in input().split())
a = [(int(i[1]), i[0]) for i in enumerate(input().split())]
arr = [(0, 0) for i in range(0, n + 1)]
a.sort()
currm = m
for i in range(1, n + 1):
    arr[i] = (a[i - 1][1], min(a[i - 1][0], (currm) // (n - i + 1)))
    currm -= arr[i][1]
arr.sort()
yes = list(i[1] for i in arr[1:])
print(max(yes) - min(yes))