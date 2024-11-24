a = tuple(map(int, input().split()))
ans = 1
for i in range(0, a[1]):
	ans = int(str(ans*a[0])[-a[2]:])
ans = str(ans)
while len(ans) < a[2]:
    ans = "0" + ans
print(ans)