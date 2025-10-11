#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m = n - 1;
    vector<int> A(m), B(m);
    vector<int> C1(m), C2(m);
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        cin >> A[i] >> B[i] >> C1[i] >> C2[i];
        adj[A[i]].push_back({B[i], i});
        adj[B[i]].push_back({A[i], i});
    }

    const int LOG = 20; 
    vector<array<int, LOG>> up(n+1);
    for (int i = 1; i <= n; ++i) for (int k = 0; k < LOG; ++k) up[i][k] = 0;
    vector<int> depth(n+1, 0), parent(n+1, 0), edge_to_parent(n+1, -1);
    vector<int> order; order.reserve(n);
    order.push_back(1);
    parent[1] = 0;
    depth[1] = 0;

    for (size_t idx = 0; idx < order.size(); ++idx) {
        int v = order[idx];
        for (auto &pe : adj[v]) {
            int to = pe.first;
            int eid = pe.second;
            if (to == parent[v]) continue;
            parent[to] = v;
            depth[to] = depth[v] + 1;
            edge_to_parent[to] = eid;
            order.push_back(to);
        }
    }
    for (int i = 1; i <= n; ++i) up[i][0] = parent[i];
    for (int k = 1; k < LOG; ++k) {
        for (int v = 1; v <= n; ++v) {
            up[v][k] = up[ up[v][k-1] ][k-1];
        }
    }

    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a,b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; ++k) if (diff & (1<<k)) a = up[a][k];
        if (a == b) return a;
        for (int k = LOG-1; k >= 0; --k) {
            if (up[a][k] != up[b][k]) {
                a = up[a][k];
                b = up[b][k];
            }
        }
        return parent[a];
    };

    vector<long long> cnt(n+1, 0);
    for (int i = 1; i <= n-1; ++i) {
        int u = i, v = i+1;
        cnt[u] += 1;
        cnt[v] += 1;
        int w = lca(u, v);
        cnt[w] -= 2;
    }

    long long total = 0;
    for (int idx = (int)order.size()-1; idx >= 0; --idx) {
        int v = order[idx];
        if (v == 1) continue; 
        int p = parent[v];

        long long times = cnt[v];
        int eid = edge_to_parent[v];

        long long sing = (long long)C1[eid] * times;
        long long multi = (long long)C2[eid];
        total += min(sing, multi);

        cnt[p] += cnt[v];
    }

    cout << total << '\n';
}