def correct():
    def spread_stones(n, operations):
        stones = [0]*n
        for operation in operations:
            i, k = operation
            i -= 1  # adjust index to 0-based
            for _ in range(k):
                stones[i] += 1
                i = (i + 1) % n  # move to the next pile in a circular manner
        return stones
    result = spread_stones(n, operations)

    return result

def wrong():

    stones = [0] * (n) * 2
    for i, k in operations:

        stones[0] += k // n
        stones[n] -= k // n
        stones[i] += 1
        stones[i + (k % n)] -= 1

        #print(*stones)

    for i in range(1, n * 2):
        stones[i] += stones[i - 1]

    return stones[:n]

from random import randint

n = 5
m = 3
operations = [(5, 3), (2, 8), (5, 5)]
print("wa:")
print(n, m)
for i in operations:
    print(*i)
print(*wrong())
print(*correct())
def debug():
    arr = stones.copy()
    for i in range(1, n * 2):
        arr[i] += arr[i - 1]
    print(*arr)
stones = [0] * (n) * 2
remqueue = []
for i, k in operations:
    
    stones[0] += k // n
    stones[n] -= k // n
    remqueue.append((i, i + k % n + 1))
    print(i, k)
    debug()
        
for i in range(1, n * 2):
    stones[i] += stones[i - 1]
for i in remqueue:
    print(*i)
    for j in range(*i):
        stones[j % n] += 1


print(stones[:n])