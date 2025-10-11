import sys
import threading
def main():
    import sys
    sys.setrecursionlimit(10**7)
    MOD = 10**9+7

    N, M = map(int, sys.stdin.readline().split())
    edges = [tuple(map(int, sys.stdin.readline().split())) for _ in range(M)]

    # Build graph for Dinic
    G = [[] for _ in range(N)]
    class Edge:
        __slots__ = ('v','cap','rev')
        def __init__(self, v, cap, rev):
            self.v = v
            self.cap = cap
            self.rev = rev

    def add_edge(u, v, c):
        G[u].append(Edge(v, c, len(G[v])))
        G[v].append(Edge(u, 0, len(G[u]) - 1))

    # Precompute powers of 3
    pow3 = [1] * M
    for i in range(1, M):
        pow3[i] = pow3[i-1] * 3

    # Add undirected edges as two directed edges
    for i, (u, v) in enumerate(edges):
        c = pow3[i]
        add_edge(u, v, c)
        add_edge(v, u, c)

    level = [0]*N
    it = [0]*N

    from collections import deque
    def bfs(s, t):
        for i in range(N): level[i] = -1
        q = deque([s])
        level[s] = 0
        while q:
            u = q.popleft()
            for e in G[u]:
                if e.cap > 0 and level[e.v] < 0:
                    level[e.v] = level[u] + 1
                    q.append(e.v)
        return level[t] >= 0

    def dfs(u, t, f):
        if u == t: return f
        for i in range(it[u], len(G[u])):
            e = G[u][i]
            if e.cap > 0 and level[e.v] == level[u] + 1:
                ret = dfs(e.v, t, min(f, e.cap))
                if ret > 0:
                    e.cap -= ret
                    G[e.v][e.rev].cap += ret
                    return ret
            it[u] += 1
        return 0

    # Dinic main
    flow = 0
    INF = sum(pow3)  # upper bound on total flow
    s, t = 0, N-1
    while bfs(s, t):
        it[:] = [0]*N
        while True:
            pushed = dfs(s, t, INF)
            if pushed == 0:
                break
            flow += pushed

    # Output mod 1e9+7
    print(flow % MOD)

if __name__ == "__main__":
    threading.Thread(target=main).start()
