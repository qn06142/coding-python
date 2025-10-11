#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    int n, c;
    long long m;
    cin >> n >> m >> c;

    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> indeg(n+1, 0);

    for (int i = 0; i < c; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].emplace_back(b, x);
        indeg[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    topo.reserve(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto &e : adj[u]) {
            int v = e.first;
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int u : topo) {
        for (auto &e : adj[u]) {
            int v = e.first;
            int w = e.second;
            a[v] = max(a[v], a[u] + w);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
    }
}
