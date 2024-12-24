import sys
from typing import List
import random
while True:
    n = random.randint(5, 10)
    m = 7
    a = [random.randint(0, n) for i in range(0, n)]
    tankSum = [0] * m
    tankCount = [0] * m
    minInstability = float('inf')
    bestAllocation = []

    def backtrack(fishIndex: int, currentInstability: int, allocation: List[int]):
        global minInstability, bestAllocation

        if fishIndex == n:
            if currentInstability < minInstability:
                minInstability = currentInstability
                bestAllocation = allocation.copy()  
            return

        if currentInstability >= minInstability:
            return

        for i in range(m):

            tankSum[i] += a[fishIndex]
            tankCount[i] += 1
            addedInstability = tankSum[i] * tankCount[i] - (tankSum[i] - a[fishIndex]) * (tankCount[i] - 1)

            allocation.append(i)
            backtrack(fishIndex + 1, currentInstability + addedInstability, allocation)
            allocation.pop()  

            tankSum[i] -= a[fishIndex]
            tankCount[i] -= 1

    a.sort(reverse=True)
    print(n, m)
    print(*a)
    backtrack(0, 0, [])
    if sorted(bestAllocation) != bestAllocation:
        print(f"Minimum Instability: {minInstability}")
        print("Best Allocation:", bestAllocation)
        break