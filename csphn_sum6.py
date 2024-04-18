def sum_digits(n):
    """Helper function to sum the digits of a number until it becomes a single digit"""
    while n > 9:
        n = sum(int(digit) for digit in str(n))
    return n
A = [sum_digits(i) for i in range(1, 100001)]

prefix_sum = [0]
for i in range(100000):
    prefix_sum.append(prefix_sum[-1] + A[i])
def solve(L, R):
    """Main function to solve the problem"""
    # Compute the prefix sum of the array
    return prefix_sum[R] - prefix_sum[L-1]

# Read the number of test cases
Q = int(input().strip())

# Process each test case
for _ in range(Q):
    L, R = map(int, input().strip().split())
    print(solve(L, R))
