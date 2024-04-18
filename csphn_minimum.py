# Use list comprehension to read the input in one line
n, k = [int(x) for x in input().split()]
alist = [int(x) for x in input().split()]

# Use a deque to store the indices of the minimum elements in each window
from collections import deque
dq = deque()

# Initialize the deque with the first window
for i in range(k):
    # Remove the indices of the elements that are larger than the current element
    while dq and alist[dq[-1]] > alist[i]:
        dq.pop()
    # Append the index of the current element
    dq.append(i)

# Print the minimum element of the first window
print(alist[dq[0]])

# Iterate over the remaining windows
for i in range(k, n):
    # Remove the indices of the elements that are out of the window
    while dq and dq[0] <= i - k:
        dq.popleft()
    # Remove the indices of the elements that are larger than the current element
    while dq and alist[dq[-1]] > alist[i]:
        dq.pop()
    # Append the index of the current element
    dq.append(i)
    # Print the minimum element of the current window
    print(alist[dq[0]])
