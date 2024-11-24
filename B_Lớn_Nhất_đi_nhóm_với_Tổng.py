import sys
input = sys.stdin.read
from collections import deque

def solve(N, K, A, B):

    currsum = sum(B[:K])

    ans = float('inf')

    dq = deque()

    for i in range(K):
        while dq and A[dq[-1]] <= A[i]:
            dq.pop()
        dq.append(i)

    ans = min(ans, currsum * A[dq[0]])

    for i in range(K, N):

        currsum += B[i] - B[i - K]

        if dq and dq[0] <= i - K:
            dq.popleft()

        while dq and A[dq[-1]] <= A[i]:
            dq.pop()
        dq.append(i)

        ans = min(ans, currsum * A[dq[0]])

    return ans

data = input().split()
index = 0
T = int(data[index])
index += 1
results = []

for _ in range(T):
    N = int(data[index])
    K = int(data[index + 1])
    index += 2
    A = list(map(int, data[index:index + N]))
    B = list(map(int, data[index + N:index + 2 * N]))
    index += 2 * N
    results.append(str(solve(N, K, A, B)))

sys.stdout.write("\n".join(results) + "\n")