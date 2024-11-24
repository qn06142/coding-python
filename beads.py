from typing import List

def solve(n: int, a: List[int]) -> int:
    k = 1
    s1 = [0] * (n + 3)
    f0 = [0] * (n + 2)
    f1 = [0] * (n + 2)
    res = 0
    a += [0]

    s1[1] = a[n] #type:ignore
    f0[n] = 1
    for i in reversed(range(1, n)):
        j = k
        while j > 0 and a[i] >= s1[j]:
            j -= 1
        if j == k:
            k += 1
            s1[k] = 0
        s1[j + 1] = max(s1[j + 1], a[i])
        f0[i] = j + 1

    k = 1
    s1 = [0] * (n + 2)
    s1[1] = 1e9 + 7#type:ignore
    f1[n] = 1
    for i in reversed(range(1, n)):
        j = k
        while j > 0 and a[i] <= s1[j]:
            j -= 1
        if j == k:
            k += 1
            s1[k] = 1e9 + 7#type:ignore
        s1[j + 1] = min(s1[j + 1], a[i])
        f1[i] = j + 1

    for i in range(1, n + 1):
        res = max(res, f0[i] + f1[i] - 1)

    return res

n = int(input())
a = [int(x) for x in input().split()]

result = solve(n, a)
print(result)