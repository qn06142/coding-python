def calc(x):
    return x * (x + 1) * (2 * x + 1) // 6
nums = []
x = 1
while calc(x) <= 1e18:
    nums.append(calc(x))
    x += 1

import bisect
input()
for i in (int(i) for i in input().split()):
    print(bisect.bisect(nums, i))