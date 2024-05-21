from bisect import bisect_left, bisect_right
from typing import List

def get_subset_sums(a: List[int], l: int, r: int) -> List[int]:
    len = r - l + 1
    res = []

    # loop through all subsets
    for i in range(1 << len):
        sum = 0
        for j in range(len):
            if i & (1 << j):
                sum += a[l + j]
        res.append(sum)

    return res

n, x = map(int, input().split())
a = list(map(int, input().split()))

left = get_subset_sums(a, 0, n // 2 - 1)
right = get_subset_sums(a, n // 2, n - 1)
left.sort()
right.sort()

ans = 0
for i in left:
    start_index = bisect_left(right, x - i)
    end_index = bisect_right(right, x - i)
    ans += end_index - start_index

print(ans)