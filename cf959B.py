def count_valid_subsegments(t, test_cases):
    results = []
    for case in test_cases:
        n, x = case[0]
        a = case[1]
        valid_count = 0
        
        # Calculate prefix sums
        prefix_sums = [0] * (n + 1)
        for i in range(n):
            prefix_sums[i + 1] = prefix_sums[i] + a[i]
        
        # Use two pointers to find valid subsegments
        for start in range(n):
            for end in range(start, n):
                segment_sum = prefix_sums[end + 1] - prefix_sums[start]
                if segment_sum <= x:
                    valid_count += 1
                else:
                    break
        
        results.append(valid_count)
    return results

# Read input
import sys
input = sys.stdin.read
data = input().split()
idx = 0
t = int(data[idx])
idx += 1

test_cases = []
for _ in range(t):
    n = int(data[idx])
    x = int(data[idx + 1])
    idx += 2
    a = list(map(int, data[idx:idx + n]))
    idx += n
    test_cases.append(((n, x), a))

# Get results
results = count_valid_subsegments(t, test_cases)

# Print results
for result in results:
    print(result)
