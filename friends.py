n, m = map(int, input().split())
friends = {}

for _ in range(m):
    u, v = map(int, input().split())
    if u not in friends:
        friends[u] = []
    if v not in friends:
        friends[v] = []
    friends[u].append(v)
    friends[v].append(u)

for i in range(1, n+1):
    if i in friends:
        friends[i].sort()
        print(" ".join(map(str, friends[i])))
    else:
        print("")