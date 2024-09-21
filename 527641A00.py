n, k = (int(i) for i in input().split())
a = sorted(int(i) for i in input().split())
from bisect import bisect_left as bisect
for i in input().split(): print("YES" if bisect(a, int(i)) != len(a) and a[bisect(a, int(i))] == int(i) else "NO")