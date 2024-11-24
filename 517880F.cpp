#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
vector<pair<int, int>> adj[100005];

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int a, b, c;
    cin >> a >> b >> c;
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<int> distA = dijkstra(a, n);
    vector<int> distB = dijkstra(b, n);
    vector<int> distC = dijkstra(c, n);
    
    int minCost = INF;
    
    for (int u = 1; u <= n; ++u) {
        minCost = min(minCost, distA[u] + distB[u] + distC[u]);
    }
    
    for (int u = 1; u <= n; ++u) {
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            int cost = min(distA[u] + distB[v] + distC[u], distA[v] + distB[u] + distC[v]) + w;
            minCost = min(minCost, cost);
        }
    }
    
    cout << minCost << endl;
    return 0;
}
