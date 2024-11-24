MOD = 998244353
def count_subsequences_occurrences(test_cases, k):
    results = []
    
    for n, s in test_cases:
        # Initialize a dictionary to store the count of each subsequence
        subseq_count = {}
        
        # Initial DP state: empty string has exactly one way to appear zero times
        subseq_count[""] = 1
        
        # Process each character in the string
        for char in s:
            new_subseq_count = subseq_count.copy()
            for subseq in subseq_count:
                new_subseq = subseq + char
                if new_subseq in new_subseq_count:
                    new_subseq_count[new_subseq] = (new_subseq_count[new_subseq] + subseq_count[subseq]) % MOD
                else:
                    new_subseq_count[new_subseq] = subseq_count[subseq]
            subseq_count = new_subseq_count
        
        # Count how many subsequences appear exactly k times
        count_exactly_k = sum(1 for v in subseq_count.values() if v == k) % MOD
        results.append(count_exactly_k)
    
    return results

# Input processing
t, k = (int(i) for i in input().split())
test_cases = []
for _ in range(t):
    n = int(input())
    s = input().strip()
    test_cases.append((n, s))

# Function call
results = count_subsequences_occurrences(test_cases, k)
for result in results:
    print(result)
