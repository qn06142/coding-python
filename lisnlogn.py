from random import randint
from bisect import bisect_left
input()
arr = [int(i) for i in input().split()]
#doing crap
currarr = [arr[0]]
for i in arr:
	if currarr[-1] < i:
		currarr.append(i)
	else:
		currarr[bisect_left(currarr, i)] = i
print(len(currarr))
def lis(arr):
    n = len(arr)
    lis = [[] for i in range(0, n)]
    lis[0].append(arr[0])
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and len(lis[i]) < len(lis[j]) + 1:
                lis[i] = lis[j].copy()
        lis[i].append(arr[i])
    return max(lis, key = len)
def lisindex(arr):
    n = len(arr)
    lis = [[] for _ in range(n)]
    lis[0].append(0)  # start with the index of the first element
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and len(lis[i]) < len(lis[j]) + 1:
                lis[i] = lis[j].copy()
        lis[i].append(i)  # append the current index
    return [i+1 for i in max(lis, key=len)]