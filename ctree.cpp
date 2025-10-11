#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int start, vector<int> &dist, vector<int> &parent) {
        dist.assign(n + 1, -1);
        parent.assign(n + 1, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        int far = start;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                    if (dist[v] > dist[far]) {
                        far = v;
                    }
                }
            }
        }
        return far;
    };

    vector<int> dist, parent;

    int u = bfs(1, dist, parent);

    int v = bfs(u, dist, parent);

    vector<int> path;
    for (int cur = v; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }

    int len = path.size();
    vector<int> cand;
    if (len % 2 == 1) {
        cand.push_back(path[len / 2]);
    } else {
        cand.push_back(path[len / 2]);
        cand.push_back(path[len / 2 - 1]);
    }
    sort(cand.begin(), cand.end());

    cout << cand.size() << '\n';
    for (int c : cand) {
        cout << c << ' ';
    }
    cout << '\n';
}