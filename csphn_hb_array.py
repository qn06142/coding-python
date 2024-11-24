n, k = tuple(int(i) for i in input().split())
a = [int(i) for i in input().split()]

k = k % n

print(a[k])