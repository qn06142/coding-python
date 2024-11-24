import sys

def min_cost_bruteforce(n, k, prices):
    # Initialize the minimum cost to a very large number
    min_cost = float('inf')
    
    # Brute-force all possible states
    def dfs(current_km, current_fuel, cost):
        nonlocal min_cost
        
        if current_km == n - 1:
            min_cost = min(min_cost, cost)
            return
        
        # Try buying fuel at the current station
        for i in range(current_km, n):
            max_reachable = min(i + k, n - 1)
            for j in range(i + 1, max_reachable + 1):
                new_fuel = current_fuel - (j - i)
                if new_fuel < 0:
                    break
                dfs(j, new_fuel, cost + prices[i])
        
        # Try to refuel at the current station
        for fuel_to_add in range(1, k - current_fuel + 1):
            for i in range(current_km + 1, n):
                if prices[i] <= prices[current_km]:
                    new_fuel = current_fuel + fuel_to_add - (i - current_km)
                    if new_fuel >= 0:
                        dfs(i, new_fuel, cost + fuel_to_add * prices[current_km])
    
    # Start the DFS from km 0 with an empty tank
    dfs(0, 0, 0)
    return min_cost

# Read input
n, k = map(int, input().split())
prices = list(map(int, input().split()))

# Calculate minimum cost using brute-force
result = min_cost_bruteforce(n, k, prices)
print(result)
