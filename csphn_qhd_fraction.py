from fractions import Fraction
from bisect import bisect_left
from sys import exit
n, w = map(int, input().split())
if w == 1:
    exit(0)
arr = [Fraction(*map(int, input().split())) for i in range(0, n)]

currarr = [arr[0]]
for i in arr:
	if currarr[-1] < i:
		currarr.append(i)
	else:
		currarr[bisect_left(currarr, i)] = i
print(len(currarr))