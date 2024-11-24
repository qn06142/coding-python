from collections import deque

def bfs(graph, start):
    distance = [-1] * len(graph)
    distance[start] = 0
    queue = deque([start])

    while queue:
        vertex = queue.popleft()
        for neighbor in graph[vertex]:
            if distance[neighbor] == -1:
                distance[neighbor] = distance[vertex] + 1
                queue.append(neighbor)

    return distance

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    x, y = map(int, input().split())
    graph[x-1].append(y-1)
    graph[y-1].append(x-1)

distance = bfs(graph, 0)
for d in distance:
    print(d)
