#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int u, v, w;
};

bool bfs(int n, vector<vector<pair<int, int>>>& adj, int maxWeight) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            
            if (!visited[neighbor] && weight <= maxWeight) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return visited[n];
}

int findMinLongestTime(int n, vector<Edge>& edges) {
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (auto& edge : edges) {
        adj[edge.u].emplace_back(edge.v, edge.w);
        adj[edge.v].emplace_back(edge.u, edge.w);
    }
    
    int left = 1, right = 1e9, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (bfs(n, adj, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    int result = findMinLongestTime(n, edges);
    
    cout << result << endl;
    
    return 0;
}
