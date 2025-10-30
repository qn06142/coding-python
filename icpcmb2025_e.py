import random
import sys
from collections import defaultdict
n, m = map(int, sys.stdin.readline().split())
edges = []
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, sys.stdin.readline().split())
    edges.append((u, v))
    adj[u].append((v, i))
    adj[v].append((u, i))

lim = 200000  
visited = [0.0] * m

for _ in range(lim):
    cur = 1
    while cur != n:
        v, eid = random.choice(adj[cur])
        visited[eid] += 1
        cur = v

cnt = [x / lim for x in visited]

edges_ = sorted(enumerate(cnt), key=lambda x: -x[1])
ans = 0.0
for rank, (eid, freq) in enumerate(edges_, start=1):
    ans += freq * rank

print(f"{ans:.3f}")