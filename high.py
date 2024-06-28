def max_couples(n, m, k, a, b):
    # Sort both lists
    a.sort()
    b.sort()
    
    i, j = 0, 0
    couples = 0
    
    # Use two pointers to find the maximum number of valid couples
    while i < n and j < m:
        if abs(a[i] - b[j]) <= k:
            # Found a valid couple
            couples += 1
            i += 1
            j += 1
        elif a[i] < b[j] - k:
            i += 1
        else:
            j += 1
    
    return couples

# Reading inputs from the console
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    result = max_couples(n, m, k, a, b)
    print(result)

