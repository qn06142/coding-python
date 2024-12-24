def min_cost_brute_force(n, a, b, positions):
    positions.sort()  # Sort the positions to process in order

    def calculate_cost(w):
        dp = [float('inf')] * (n + 1)
        dp[0] = 0  # Base case: No cost to paint 0 cells

        for i in range(1, n + 1):
            # Use brush of size w
            j = i - 1
            while j >= 0 and positions[j] >= positions[i - 1] - w + 1:
                j -= 1
            dp[i] = min(dp[i], dp[j + 1] + a)

            # Use brush of size 2w
            j = i - 1
            while j >= 0 and positions[j] >= positions[i - 1] - 2 * w + 1:
                j -= 1
            dp[i] = min(dp[i], dp[j + 1] + b)

        return dp[n]

    # Brute force over possible values of w
    best_w = float('inf')
    for w in range(1, max(positions) + 1):  # Try all possible values of w
        cost = calculate_cost(w)
        if cost < float('inf'):  # If a valid cost is found, update best_w
            best_w = min(best_w, w)
            break

    return best_w
n, m, k = (int(i) for i in input().split())
a = list(int(i) for i in input().split())
print(min_cost_brute_force(n, m, k, a))