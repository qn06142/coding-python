def solve(n, k, stones):
    def is_feasible(x):

        tmp = [c - x * w for w, c in stones]

        tmp.sort(reverse=True)

        return sum(tmp[:k]) >= 0

    low, high = 0, 10**6
    for _ in range(100):  
        mid = (low + high) / 2
        if is_feasible(mid):
            low = mid  
        else:
            high = mid  

    return int(low)  

n, k = map(int, input().split())
stones = [
    tuple(int(i) for i in input().split()) for i in range(0, n)
]

print(solve(n, k, stones))  