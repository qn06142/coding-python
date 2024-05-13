n, m, k = tuple(int(i) for i in input().split())
arr = []
for i in range(1, n + 1):
    for j in  range(1, m + 1):
        arr.append(i * j)
arr.sort()
print(arr[k - 1])