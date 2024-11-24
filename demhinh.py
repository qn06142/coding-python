n = int(input())
m = int(input())
count = 0
for i in range(1, min(n, m) + 1, 2):
    count += (n - i + 1) * (m - i + 1)
print(count)
