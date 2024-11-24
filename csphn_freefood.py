import heapq

n, T = map(int, input().split())
res = 0
cur = 0
pq = []
a = sorted(tuple(int(i) for i in input().split()) for i in range(0, n))
for i in a:
    x, t = i
    cur += t
    heapq.heappush(pq, -t)  # Using min heap with negative values to simulate max heap
    
    while cur + x > T and pq:
        cur += heapq.heappop(pq)
    
    res = max(res, len(pq))

print(res)
