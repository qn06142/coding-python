def longest_arithmetic_subarray(n, A):
    if n < 2:
        return n
    longest = 2
    diff = A[1] - A[0]
    current_length = 2
    for i in range(2, n):
        if A[i] - A[i-1] == diff:
            current_length += 1
        else:
            diff = A[i] - A[i-1]
            current_length = 2
        longest = max(longest, current_length)
    return longest

n = int(input().strip())
A = list(map(int, input().strip().split()))

print(longest_arithmetic_subarray(n, A))
