def can_form_k_pairs(a, b, K, max_diff):
    i, j = 0, 0
    pairs = 0

    while i < len(a) and j < len(b):
        if abs(a[i] - b[j]) <= max_diff:
            pairs += 1
            i += 1
            j += 1
            if pairs == K:
                return True
        elif a[i] < b[j]:
            i += 1
        else:
            j += 1

    return False

def check(a, b, K):
    a.sort()
    b.sort()

    left, right = 0, 10**9  
    result = right

    while left <= right:
        mid = (left + right) // 2
        if can_form_k_pairs(a, b, K, mid):
            result = mid
            right = mid - 1  
        else:
            left = mid + 1  

    return result
with open("pair.inp", "r") as f:
    B, G, K = map(int, f.readline().split())
    a = list(map(int, f.readline().split()))
    b = list(map(int, f.readline().split()))
with open("pair.out", "w") as f:
    f.write(str(check(a, b, K)))