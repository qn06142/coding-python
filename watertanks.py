n = int(input())
a = [int(i) for i in input().split()]
l = 0
r = n - 1
area = 0
while l < r:
	area = max(area, min(A[l], A[r]) * (r - l))
	if A[l] < A[r]:
		l += 1
	else:
		r -= 1
print(area)