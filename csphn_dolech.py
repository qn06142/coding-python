def count_pairs(A, N, K):
    A.sort()
    if K == 0:
        # To store the required count
        count = 0
    
        # Sort the original Aay
        A.sort()
    
        i = 0
        n = len(A)
        while i < n - 1:
    
            # A valid pair is found
            if A[i] == A[i + 1]:
                count += 1
    
                # Skip the elements of
                # the current pair
                i += 2
    
            # Current elements doesn't make
            # a valid pair with any other element
            else:
                i += 1
    
        return count
    else:
        count = 0
        from bisect import bisect_right, bisect_left
        for i in range(0, N):
            tmp = bisect_left(A, A[i] + K)
            tmp1 = bisect_right(A, A[i] + K)
            count += tmp1 - tmp
        return count


N, K = map(int, input().split())
A = list(map(int, input().split()))

print(count_pairs(A, N, K))
