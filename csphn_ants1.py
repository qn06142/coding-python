def is_feasible(T, piles, k):

    intervals = []
    for (x, a) in piles:
        D = T // (2 * a)
        L = x - D
        R = x + D
        intervals.append((L, R))

    intervals.sort(key=lambda interval: interval[1])

    cnt = 0
    current = -10**18  
    for (L, R) in intervals:
        if current < L:

            current = R
            cnt += 1
            if cnt > k:
                return False
    return True

def find_min_T(piles, k):

    xs = [x for (x, a) in piles]
    l = 0
    r = 2 * max(a for (x, a) in piles) * (max(xs) - min(xs))
    while l < r:
        mid = (l + r) // 2
        if is_feasible(mid, piles, k):
            r = mid
        else:
            l = mid + 1
    return l

n, k = (int(i) for i in input().split())
a = list(int(i) for i in input().split())
b = list(int(i) for i in input().split())
piles = list(zip(a, b))
T_min = find_min_T(piles, k)
print(T_min)