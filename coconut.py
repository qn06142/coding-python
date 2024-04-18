def min_time_to_start_processing(N, M, A, B, C, D, T):
    def check(mid):
        gather = [max(0, (mid - A[i]) // B[i]) for i in range(N)]
        process = [max(0, (mid - C[i]) // D[i]) for i in range(M)]
        gather.sort()
        process.sort()
        return sum(gather) <= sum(process)

    left, right = 0, T
    while left < right:
        mid = (left + right) // 2
        if check(mid):
            right = mid
        else:
            left = mid + 1
    return left
T = int(input())
N = int(input())
A = []
B = []
for _ in range(0, N):
    tmp = tuple(int(i) for i in input().split())
    A.append(tmp[0])
    B.append(tmp[1])
C = []
D = []
M = int(input())
for _ in range(0, M):
    tmp = tuple(int(i) for i in input().split())
    C.append(tmp[0])
    D.append(tmp[1])

print(min_time_to_start_processing(N, M, A, B, C, D, T))
