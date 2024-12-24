input()
a = sorted(int(i) for i in input().split())
print(sum(abs(a[i - 1] - a[i]) for i in range(1, len(a))))