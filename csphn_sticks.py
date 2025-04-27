import heapq

def minCost(arr):
    heapq.heapify(arr)
    res = 0
    while len(arr) > 1:
        first = heapq.heappop(arr)
        second = heapq.heappop(arr)
        res += first + second
        heapq.heappush(arr, first + second)
    return res

x, n = map(int, input().split())
arr = list(map(int, input().split()))

print(minCost(arr))
