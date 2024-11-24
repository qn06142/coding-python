n = int(input())
arr = [int(i) for i in input().split()]
search = sorted(arr.copy())

from bisect import bisect_left
for i in arr:
    tmp = bisect_left(search, i)
    if i:
        print(i)
    else:
        print(0)