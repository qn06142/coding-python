def count_distinct_values(N, M, commands, queries):
    prefix = [0]*(N+2)
    mx = [[0]*2 for _ in range(N+2)]
    mn = [[0]*2 for _ in range(N+2)]
    s = '?' + commands
    for i in range(1, N+1):
        prefix[i] = prefix[i-1] + (1 if s[i] == '+' else -1)
        mx[i][0] = max(mx[i-1][0], prefix[i])
        mn[i][0] = min(mn[i-1][0], prefix[i])
    mn[N+1][1] = mx[N+1][1] = prefix[N]
    for i in range(N, 0, -1):
        mx[i][1] = max(mx[i+1][1], prefix[i])
        mn[i][1] = min(mn[i+1][1], prefix[i])
    for l, r in queries:
        l1 = mn[l-1][0]
        r1 = mx[l-1][0]
        l2 = mn[r+1][1] - (prefix[r] - prefix[l-1])
        r2 = mx[r+1][1] - (prefix[r] - prefix[l-1])
        print(max(r1, r2) - min(l1, l2) + 1)

n, m = tuple(int(i) for i in input().split())
a = input()
queries = [tuple(map(int, input().split())) for _ in range(m)]
count_distinct_values(n, m, a, queries)
