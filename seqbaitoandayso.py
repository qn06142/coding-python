def max_score(A, N):
    # Define a recursive function to calculate the maximum score
    def helper(A, start, end):
        if start >= end:
            return 0

        for mid in range(start, end):
            if sum(A[start:mid+1]) == sum(A[mid+1:end+1]):
                return max(helper(A, start, mid+1), helper(A, mid+1, end)) + 1

        return 0

    # Call the recursive function with the initial array
    return helper(A, 0, len(A))

for i in range(0, int(input())):
    N = int(input())
    A = [int(i) for i in input().split()]
    print(max_score(A, N))
