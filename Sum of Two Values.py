n, target = list(map(int, input().split()))
from itertools import accumulate
nums = list(map(int, input().split()))
nums = [0] + list(accumulate(nums))
currmax = 0
r = l = 1
while r <= n:
	currsum = nums[r] - nums[l-1]
	if currsum <= target:
	  r += 1
	else:
	  l += 1
	currmax = max(currmax, r-l)
print(currmax)
