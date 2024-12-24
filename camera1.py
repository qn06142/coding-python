from itertools import accumulate
from bisect import bisect_left

n = int(input())
a = list(map(int, input().split()))
sa = sorted(a)

psa = [0] + list(accumulate(sa))


def calc(x):
    ind = bisect_left(sa, x)
    left_sum = x * ind - psa[ind]
    right_sum = (psa[-1] - psa[ind]) - x * (n - ind)
    return left_sum + right_sum

min_dist = calc(0)
result_positions = []
max_ = max(a)
min_ = min(a)
mid = (max_ + min_) // 2

l = max(mid - 10 ** 5, min_)
r = min(mid + 10 ** 5, max_)
count = []
for x in range(l, r):
    total_dist = calc(x)
    if total_dist < min_dist:
        min_dist = total_dist
        count = [x]
    elif total_dist == min_dist:
        count .append(x)
print(len(count))
print(*count)