#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> a;

void dfs(int u, int &min_cost) {
    visited[u] = 1;
    min_cost = min(min_cost, a[u]);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, min_cost);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    a.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long total_cost = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int min_cost = a[i];
            dfs(i, min_cost);
            total_cost += min_cost;
        }
    }

    cout << total_cost << '\n';

    return 0;
}
