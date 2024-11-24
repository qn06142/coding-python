def calculate_minimum_cost(n, c, heights):
    # Initial cost without any modification
    original_cost = c * sum(abs(heights[i] - heights[i+1]) for i in range(n-1))
    min_cost = original_cost
    
    # Try increasing each pole height by x (0 <= x <= 1000)
    for i in range(n):
        for x in range(0, 1001):
            # Calculate new heights
            new_heights = heights[:]
            new_heights[i] += x
            
            # Calculate new cost
            new_cost = c * sum(abs(new_heights[j] - new_heights[j+1]) for j in range(n-1)) + x * x
            
            # Update minimum cost
            min_cost = min(min_cost, new_cost)
    
    return min_cost

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])
    c = int(data[1])
    heights = list(map(int, data[2:]))
    
    result = calculate_minimum_cost(n, c, heights)
    print(result)

if __name__ == "__main__":
    main()