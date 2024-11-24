import heapq

def k_smallest_product_pairs(a, b, k):
    if not a or not b:
        return []
    min_heap = []
    pairs = []
    for i in range(len(a)):
        for j in range(len(b)):
            if len(min_heap) < k:
                heapq.heappush(min_heap, (-a[i]*b[j], (a[i], b[j])))
            else:
                if a[i]*b[j] < -min_heap[0][0]:
                    heapq.heappop(min_heap)
                    heapq.heappush(min_heap, (-a[i]*b[j], (a[i], b[j])))
                else:
                    break
    while min_heap:
        pair = heapq.heappop(min_heap)
        pairs.append((pair[1][0], pair[1][1], -pair[0]))
    return pairs[::-1]

# Test the function
n, k = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

print(k_smallest_product_pairs(a, b, k))
