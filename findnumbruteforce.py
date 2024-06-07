import heapq

def min_operations(a, n, k, m, r):

    heapq.heapify(a)
    operations = 0
    while a[0] < k:

        min_element = heapq.heappop(a)

        min_element += m

        heapq.heappush(a, min_element)

        for i in range(1, len(a)):
            a[i] -= r
        operations += 1
    return operations
for _ in range(0, int(input())):
    n, k, m, r = (int(i) for i in input().split())
    a = list(int(i) for i in input().split())
    print(min_operations(a, n, k, m, r))