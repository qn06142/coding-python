n, k = map(int, input().split())
a = [0] + list(map(int, input().split()))
b = [0] * (n + 1)
b[1] = 1
for i in range(2, n + 1):
    b[i] = 1
for i in range(1, k + 1):
    b[a[i]] = 0
for i in range(2, n + 1):
    if b[i] != 0:
        b[i] = (b[i - 1] + b[i - 2]) % 14062008
print(b[n])
