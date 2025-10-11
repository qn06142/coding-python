import sys
from bisect import bisect_right
a=list(map(int,sys.stdin.buffer.read().split()))
if not a:
    raise SystemExit
n=a[0]
h=a[1:1+n]
tops=[]
piles=[]
for i,x in enumerate(h,1):
    pos=bisect_right(tops,x)
    if pos==len(tops):
        tops.append(x)
        piles.append([i])
    else:
        tops[pos]=x
        piles[pos].append(i)
print(len(piles))
for p in piles:
    print(len(p), *p)