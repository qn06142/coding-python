import heapq
import sys

MAXD = 10**12 + 5

def dijkstra(n, graph, start, end):
    distances = [MAXD] * (n + 1)
    count_paths = [0] * (n + 1)
    distances[start] = 0
    count_paths[start] = 1
    
    priority_queue = [(0, start)]  # (distance, vertex)
    
    while priority_queue:
        current_distance, u = heapq.heappop(priority_queue)
        
        if current_distance > distances[u]:
            continue
        
        for v, length in graph[u]:
            distance = current_distance + length
            
            if distance < distances[v]:
                distances[v] = distance
                count_paths[v] = count_paths[u]
                heapq.heappush(priority_queue, (distance, v))
            elif distance == distances[v]:
                count_paths[v] += count_paths[u]
    
    return distances[end], count_paths[end]

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    
    graph = [[] for _ in range(n + 1)]
    
    index = 2
    for _ in range(m):
        k = int(data[index])
        u = int(data[index + 1])
        v = int(data[index + 2])
        l = int(data[index + 3])
        
        graph[u].append((v, l))
        if k == 2:
            graph[v].append((u, l))
        
        index += 4
    
    start = 1
    end = n
    
    shortest_distance, number_of_paths = dijkstra(n, graph, start, end)
    
    print(shortest_distance, number_of_paths)

if __name__ == "__main__":
    main()
