from bisect import bisect_left, bisect_right

n = int(input())
a = sorted(int(i) for i in input().split())

for _ in range(0, int(input())):
    l = int(input())
    r = int(input())
    print(bisect_right(a, r) - bisect_left(a, l))