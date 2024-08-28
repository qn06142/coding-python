#include <bits/stdc++.h>
using namespace std;

vector<int> findLexSmallestPath(int n, vector<vector<int>>& adj, int s, int t) {
    vector<bool> visited(n + 1, false);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // Start with the initial path containing only the start node s
    pq.push({s});

    while (!pq.empty()) {
        vector<int> path = pq.top();
        pq.pop();
        int u = path.back();

        // If we reach the target node t, return the path
        if (u == t) {
            return path;
        }

        // Mark this node as visited in this particular path context
        if (!visited[u]) {
            visited[u] = true;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    vector<int> new_path = path;
                    new_path.push_back(v);
                    pq.push(new_path);
                }
            }
        }

        // Reset visited for the current node to allow other paths
        visited[u] = false;
    }

    return {}; // This shouldn't happen if there's guaranteed to be a path
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // Sort adjacency list for lexicographical order
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<int> result = findLexSmallestPath(n, adj, s, t);
    for (int v : result) {
        cout << v << " ";
    }
    
    return 0;
}
