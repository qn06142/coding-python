import sys
from bisect import bisect_left

n = int(sys.stdin.readline().strip())
a = list(map(int, sys.stdin.readline().split()))

total = sum(a)
mid = n // 2
l = a[:mid]
r = a[mid:]

def subset(arr):
    sums = [0]
    for x in arr:
        
        sums += [s + x for s in sums]
    return sums

sl = subset(l)   
sr = subset(r)   
sr.sort()

target = total / 2.0
ans = 10**30

for s in sl:
    need = target - s
    i = bisect_left(sr, need)
    
    for j in (i-1, i):
        if 0 <= j < len(sr):
            sub = s + sr[j]
            diff = abs(total - 2 * sub)
            if diff < ans:
                ans = diff

print(ans)
