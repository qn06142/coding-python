n, m = map(int, input().split())

b = [sum(int(j) for j in i) for i in input().split()]
a = [sum(int(j) for j in i) for i in input().split()]
from collections import defaultdict
cnt = defaultdict(int)
for i in b:
    cnt[i % 3] += 1

for i in a:
    print(cnt[(3 - i % 3) % 3], flush=False)