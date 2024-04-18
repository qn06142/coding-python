n, k = tuple(int(i) for i in input().split())
a = [0] + list(i.count('3') for i in input().split())

ans = 0
curr = 0
j = 1
for i in range(1, n + 1):
    curr += a[i]
    while curr >= k:
        curr -= a[j]
        j += 1
    if i >= j:
        ans += i - j + 1
print(ans)