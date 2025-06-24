import sys
input = sys.stdin.readline

n, k, x = map(int, input().split())
prices = list(map(int, input().split()))

INF = 10**30

mask_width = k - 1
mask_full = (1 << mask_width) - 1

dp = {0: 0}

for i in range(n):
    new_dp = {}
    price = prices[i]
    for mask, cost in dp.items():

        for b in (0, 1):

            cnt = mask.bit_count() + b

            if i + 1 >= k:
                if cnt != x:
                    continue
            else:

                if cnt > x:
                    continue

            new_mask = ((mask << 1) | b) & mask_full
            new_cost = cost + (0 if b else price)

            prev = new_dp.get(new_mask)
            if prev is None or new_cost < prev:
                new_dp[new_mask] = new_cost

    dp = new_dp

ans = min(dp.values())
print(ans)