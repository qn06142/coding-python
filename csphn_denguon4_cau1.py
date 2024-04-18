n, k = tuple(int(i) for i in input().split())
a = 0
b = 0
for i in range(1, n + 1, 2*k):
    a_end = min(i + k - 1, n)
    a += ((a_end - i + 1) * (i + a_end)) // 2
    if a_end < n:
        b_start = a_end + 1
        b_end = min(b_start + k - 1, n)
        b += ((b_end - b_start + 1) * (b_start + b_end)) // 2
print(b - a)
