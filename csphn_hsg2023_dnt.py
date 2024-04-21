from itertools import combinations

def count_inversions(A):
    return sum(1 for i in range(len(A)) for j in range(i+1, len(A)) if A[i] > A[j])

def min_inversions(A, k, n):
    min_inv = float('inf')
    
    # Generate all possible sequences after k operations
    for comb in combinations(range(n), k):
        B = A.copy()
        for i in comb:
            B[i] = 1 - B[i]  # flip the bit
        inv = count_inversions(B)
        min_inv = min(min_inv, inv)
    
    return min_inv

n, k = tuple(int(i) for i in input().split())
a = list(int(i) for i in input().split())
print(min_inversions(a, k, n))