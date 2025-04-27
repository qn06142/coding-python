n = int(input())
from collections import defaultdict
cnt = defaultdict(int)
for i in range(0, n):
    cnt[input()] += 1
for i in cnt:
    if cnt[i] % 2 == 1:
        print(i)
        from sys import exit
        exit(0)