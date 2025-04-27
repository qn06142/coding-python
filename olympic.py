import heapq
n, c = (int(i) for i in input().split())
tasks = list(tuple(int(i) for i in input().split()) for i in range(0, n))
tasks.sort(key=lambda x: x[0])  
count = 0
i = 0
heap = []  

while True:

    while i < n and tasks[i][0] <= c:

        heapq.heappush(heap, -tasks[i][1])
        i += 1

    if not heap:
        break  

    c += -heapq.heappop(heap)
    count += 1
print(count)