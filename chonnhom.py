import itertools

def max_cooperation(n, k, a):
    max_total = -float('inf')
    for groups in itertools.combinations(a, 3*k):
        total = 0
        for i in range(0, len(groups), 3):
            total += groups[i] * groups[i+1] * groups[i+2]
        max_total = max(max_total, total)
    return max_total

n, k = map(int, input().split())
a = list(map(int, input().split()))
print(max_cooperation(n, k, a))
