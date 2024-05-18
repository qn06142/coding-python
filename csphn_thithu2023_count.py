n, m = tuple(int(i) for i in input().split())
a = [int(i) for i in input().split()]
b = [(i[0], int(i[1])) for i in enumerate(list(set(input().split())))]
a.append(0)
b.append((0, 0))
a.sort()
b.sort(key =lambda x: x[1])
print(*b)
i = 1
j = 1
ans = []
while i <= m:
    while j + 1 <= n and a[j + 1] < b[i][1]: j += 1
    ans.append((b[i][0], b[i][1] - j - 1))
    i += 1
ans.sort()
for i in ans:
    print(i[1])