def transform_string(s, operations):
    n = len(s)
    s = list(s)
    changes = [None] * n
    for operation in reversed(operations):
        i, j, c1, c2, _ = operation
        if changes[i]:
            changes[i] = max((i, _, c1, c2), changes[i], key = lambda x: x[1])
        else:
            changes[i] = (i, _, c1, c2)
        if changes[i]:
            changes[i] = max((i, _), changes[i], key = lambda x: x[1])
        else:
            changes[i] = (i, _)
    curr = (-1, -1)
    for i in range(n):
        curr = max()
        s[i] = changes[i]
    return ''.join(s)
from collections import deque
s = input()
ops = []
for _ in range(0, int(input())):
    i = input().split()
    ops.append(tuple((int(i[0]), int(i[1]), i[2], i[3], _)))
print(ops)
print(transform_string(s, ops))