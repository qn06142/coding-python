def max_subsequence_sum(arr):
    max_element = max(arr)
    if max_element < 0:
        return max_element
    return sum(x for x in arr if x > 0)

def max_subarray_sum(arr):
    max_ending_here = max_so_far = arr[0]
    for x in arr[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

def solve(t, test_cases):
    results = []
    for case in test_cases:
        n, arr = case
        max_subseq = max_subsequence_sum(arr)
        max_subarr = max_subarray_sum(arr)
        results.append((max_subseq, max_subarr))
    return results

# Input reading and parsing
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    test_cases.append((n, arr))

# Solve and print results
results = solve(t, test_cases)
for result in results:
    print(result[0], result[1])
