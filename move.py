import bisect

def solve(n, m, board):

    row_costs = []  

    for row in board:
        ones = [i for i, ch in enumerate(row) if ch == '1']
        if not ones:
            return -1  
        cost = [0] * m
        for j in range(m):

            pos = bisect.bisect_left(ones, j)

            d1 = abs(ones[pos] - j) if pos < len(ones) else float('inf')

            d2 = abs(j - ones[pos-1]) if pos > 0 else float('inf')

            best = min(d1, d2)
            best = min(best, m - best)
            cost[j] = best
        row_costs.append(cost)

    ans = float('inf')
    for j in range(m):
        total = sum(row_costs[i][j] for i in range(n))
        ans = min(ans, total)
    return ans


import sys
data = sys.stdin.read().strip().split()
if not data: 
    exit(0)
n, m = map(int, data[:2])
board = data[2:]
result = solve(n, m, board)
print(result)