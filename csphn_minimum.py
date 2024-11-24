n, k = [int(x) for x in input().split()]
alist = [int(x) for x in input().split()]

from collections import deque
dq = deque()

for i in range(k):

    while dq and alist[dq[-1]] > alist[i]:
        dq.pop()

    dq.append(i)

print(alist[dq[0]])

for i in range(k, n):

    while dq and dq[0] <= i - k:
        dq.popleft()

    while dq and alist[dq[-1]] > alist[i]:
        dq.pop()

    dq.append(i)

    print(alist[dq[0]])