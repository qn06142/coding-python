import sys
from typing import List, Tuple

def max_boxes(n: int, boxes: List[Tuple[int, int]]) -> int:
    boxes.sort(key=lambda x: x[0] + x[1])
    top = sum(w for w, _ in boxes)
    dp = [0] * (top + 1)
    res = 0

    for i in range(n):
        for j in range(min(top, boxes[i][0] + boxes[i][1]), boxes[i][0] - 1, -1):
            dp[j] = max(dp[j], dp[j - boxes[i][0]] + 1)
            res = max(res, dp[j])

    return res

n = int(sys.stdin.readline())
weights = list(map(int, sys.stdin.readline().split()))
capacities = list(map(int, sys.stdin.readline().split()))
boxes = list(zip(weights, capacities))
print(max_boxes(n, boxes))
