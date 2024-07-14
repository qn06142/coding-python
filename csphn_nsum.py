def sum_floor_divisions(n):
    total = 0
    k = 1
    while k <= n:
        q = n // k
        next_k = n // q + 1
        total += q * (next_k - k)
        k = next_k
    return total

n = int(input())
print(sum_floor_divisions(n))
