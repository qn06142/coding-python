def is_intersect(arc1, arc2):
    a1, b1 = arc1
    a2, b2 = arc2
    return (a1 < a2 < b1 < b2) or (a2 < a1 < b2 < b1)
def is_intersect_(arc1, arc2):
    a1, b1 = arc1
    a2, b2 = arc2
    return not ((a1 < a2 < b1 < b2) or (a2 < a1 < b2 < b1))
from functools import cmp_to_key
def max_non_overlapping_arcs(n, arcs):

    arcs.sort(key=cmp_to_key(is_intersect_))

    dp = [1] * n

    for i in range(n):
        for j in range(i):

            if not is_intersect(arcs[j], arcs[i]):
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)

n = int(input())  
arcs = []

for _ in range(n):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a  
    arcs.append((a, b))

result = max_non_overlapping_arcs(n, arcs)
print(result)