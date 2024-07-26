from collections import deque

def sum_of_digits(x):
    return sum(int(digit) for digit in str(x))

def bfs_with_memoization(L, R, M, K):
    # Memoization table to store the minimum result for given (remainder, digit_sum)
    visited = set()  # (remainder, digit_sum) to avoid redundant states
    queue = deque([(K, K % M, sum_of_digits(K))])  # (current_number, current_remainder, current_digit_sum)
    
    while queue:
        N, remainder, digit_sum = queue.popleft()
        
        # Check if current number satisfies the conditions
        if L <= digit_sum <= R and remainder == K % M:
            return N
        
        # Generate next numbers and push them to the queue
        for digit in range(10):
            new_number = N * 10 + digit
            new_remainder = new_number % M
            new_digit_sum = sum_of_digits(new_number)
            
            state = (new_remainder, new_digit_sum)
            
            if state not in visited:
                visited.add(state)
                queue.append((new_number, new_remainder, new_digit_sum))
    
    return -1

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    
    results = []
    
    for _ in range(t):
        L = int(data[index])
        R = int(data[index + 1])
        M = int(data[index + 2])
        K = int(data[index + 3])
        index += 4
        
        result = bfs_with_memoization(L, R, M, K)
        results.append(result)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
