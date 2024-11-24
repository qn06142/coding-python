#same problem as cpp version
isprime = [0 for i in range(0, 10 ** 6 + 1)]
isprime[1] = 1
for i in range(2, 10 ** 6 + 1):
    if isprime[i] == 0:
        for j in range(2, 10 ** 6 // i + 1):
            isprime[i * j] = 1;
n = int(input())
a = tuple(int(i) for i in input().split())
for i in range(0, n):
    cnt = 0
    if (a[i] ** 0.5) % 1 == 0:
        if isprime[int(a[i] ** 0.5)] == 0:
            print("YES")
            cnt += 1
    if not cnt:
        print("NO")