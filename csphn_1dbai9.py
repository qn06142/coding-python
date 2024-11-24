size = int(input())
a = tuple([int(i) for i in input().split()])
count = 0
for i, _ in enumerate(a[1:-1]):
	if a[i-1] >a[i] < a[i+1]:
		count += 1
print(count)