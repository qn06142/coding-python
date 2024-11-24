#works, but faster version in c++ (doesn't work?)
def count_beautiful_subarrays(A, N):
    count = 0
    freq = [0] * (max(A) + 1)

    l = 0
    for r in range(N):
        freq[A[r]] += 1
        while freq[A[r]] > 2:
            freq[A[l]] -= 1
            l += 1
        count += r - l + 1
    return count
N = int(input())
A = [int(i) for i in input().split()]
print(count_beautiful_subarrays(A, N))