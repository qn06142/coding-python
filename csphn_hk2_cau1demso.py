n, k = tuple(int(i) for i in input().split())

divs = [0 for i in range(0, n + 1)]

for i in range(1, n + 1):
    for j in range(i, n + 1, i):
        divs[j] += 1
count = 0
for i in range(1, n + 1):
    if divs[i] == k:
        count += 1
print(count)