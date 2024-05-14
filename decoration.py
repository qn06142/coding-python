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