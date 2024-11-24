import sys
input = sys.stdin.read
data = input().split()

index = 0
m = int(data[index])
q = int(data[index + 1])
index += 2

friend_dict = {}

for _ in range(m):
    u = int(data[index])
    v = int(data[index + 1])
    index += 2
    if u not in friend_dict:
        friend_dict[u] = set()
    if v not in friend_dict:
        friend_dict[v] = set()
    friend_dict[u].add(v)
    friend_dict[v].add(u)

queries = []
for _ in range(q):
    xi = int(data[index])
    index += 1
    queries.append(xi)

for xi in queries:
    if xi in friend_dict:
        result = sorted(friend_dict[xi])
        print(" ".join(map(str, result)))
    else:
        print("")  