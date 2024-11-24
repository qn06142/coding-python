from collections import deque

for _ in range(0, int(input())):
    hmmm = deque()
    n, k = (int(i) for i in input().split())
    a = [int(i) for i in input().split()]
    min_values = []
    for i in range(n):
        while hmmm and a[hmmm[-1]] > a[i]:
            hmmm.pop()
        hmmm.append(i)
        if i >= k and hmmm[0] == i - k:
            hmmm.popleft()
        if i >= k - 1:
            min_values.append(a[hmmm[0]])
    print(*min_values)
