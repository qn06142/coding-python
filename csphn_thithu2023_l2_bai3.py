n = int(input())
a = list(map(int, input().split()))
prefix_sum = [0]*(n+1)
suffix_sum = [0]*(n+2)
prefix_max = [0]*(n+1)
suffix_max = [0]*(n+2)
for i in range(1, n+1):
    prefix_sum[i] = prefix_sum[i-1] + a[i-1]
    prefix_max[i] = max(prefix_max[i-1], prefix_sum[i] - prefix_sum[i - k])
for i in range(n, 0, -1):
    suffix_sum[i] = suffix_sum[i+1] + a[i-1]
    suffix_max[i] = max(suffix_max[i+1], suffix_sum[i + k] - suffix_sum[i])
res = max(prefix_max[i-1]*suffix_max[i+1] for i in range(1, n+1))
print(res)
