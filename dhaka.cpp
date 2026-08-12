#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n, m;
vector<pair<int, int>> adj[maxn];
bool is_bridge[2 * maxn];
int tin[maxn], low[maxn], timer;
int comp_id[maxn];
vector<int> adj1[maxn];

void dfs1(int u, int p_idx) {
    tin[u] = low[u] = ++timer;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int e_idx = edge.second;
        if (e_idx == p_idx) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs1(v, e_idx);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                is_bridge[e_idx] = true;
            }
        }
    }
}

void dfs2(int u, int cid) {
    comp_id[u] = cid;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int e_idx = edge.second;
        if (is_bridge[e_idx] || comp_id[v] != -1) continue;
        dfs2(v, cid);
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        adj[i].clear();
        tin[i] = 0;
        low[i] = 0;
        comp_id[i] = -1;
        adj1[i].clear();
    }
    for (int i = 0; i < m; i++) {
        is_bridge[i] = false;
    }
    timer = 0;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges.push_back({u, v});
    }

    for (int i = 0; i < n; i++) {
        if (!tin[i]) {
            dfs1(i, -1);
        }
    }

    int comps = 0;
    for (int i = 0; i < n; i++) {
        if (comp_id[i] == -1) {
            dfs2(i, comps++);
        }
    }

    if (comps == 1) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < comps; i++) {
        adj1[i].clear();
    }

    for (int i = 0; i < m; i++) {
        if (is_bridge[i]) {
            int u = edges[i].first;
            int v = edges[i].second;
            int cu = comp_id[u];
            int cv = comp_id[v];
            adj1[cu].push_back(cv);
            adj1[cv].push_back(cu);
        }
    }

    int leaves = 0;
    for (int i = 0; i < comps; i++) {
        if (adj1[i].size() == 1) {
            leaves++;
        }
    }

    cout << (leaves + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
}