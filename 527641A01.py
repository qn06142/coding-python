n, k = (int(i) for i in input().split())
a = sorted(int(i) for i in input().split())
from bisect import bisect_right as bisect
for i in input().split(): print(max(0, bisect(a, int(i))))