out = 0
m , n = tuple(int(i) for i in input().split())
for i in range(0, m):
	out += int(input())
print(str(out)[:n])