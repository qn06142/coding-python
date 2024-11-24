def max_matches(n, d, s):
    matches = 0
    
    # Initialize two pointers
    i = 0
    j = 1
    
    # While the second pointer is within the range
    while j < n:
        # If the brightness difference is within the limit
        if s[j] - s[i] <= d:
            # Increase the number of matches
            matches += 1
            # Move both pointers two steps forward
            i += 2
            j += 2
        else:
            # Move the first pointer one step forward
            i += 1
            # Move the second pointer to the next position of the first pointer
            j = i + 1
    
    # Return the number of matches
    return matches

n, d = tuple(int(i) for i in input().split())
a = [int(i) for i in input().split()]
a.sort()
print(max_matches(n, d, a))