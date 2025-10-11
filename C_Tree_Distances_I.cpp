#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> bfs(int start, const vector<vector<int>>& adj) {
    int n = (int)adj.size() - 1;
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int far_node = start;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > dist[far_node]) far_node = i;
    }
    return {far_node, dist};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // 1) BFS from node 1 to find u
    auto res1 = bfs(1, adj);
    int u = res1.first;

    // 2) BFS from u to get dist_u and find v
    auto res2 = bfs(u, adj);
    int v = res2.first;
    vector<int> dist_u = res2.second;

    // 3) BFS from v to get dist_v
    auto res3 = bfs(v, adj);
    vector<int> dist_v = res3.second;

    // 4) For each node, answer is max(dist_u[i], dist_v[i])
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << max(dist_u[i], dist_v[i]);
    }
    cout << '\n';
    return 0;
}
