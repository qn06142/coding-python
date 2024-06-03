
n, m = map(int, input().split())

a = []
for i in range(n):
    a.append(list(map(int, input().split())))

for i in range(n):
    for j in range(1, m):
        a[i][j] += a[i][j-1]

max_sum = -1e18
for l in range(m):
    for r in range(l, m):
        sum = [0]*n
        for i in range(n):
            sum[i] = a[i][r] - (a[i][l-1] if l > 0 else 0)

        max_ending_here = max_ending_so_far = sum[0]
        for i in range(1, n):
            max_ending_here = max(sum[i], max_ending_here + sum[i])
            max_ending_so_far = max(max_ending_so_far, max_ending_here)

        max_sum = max(max_sum, max_ending_so_far)

print(max_sum)
