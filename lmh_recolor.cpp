#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) : parent(n+1), sz(n+1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find_set(int v) {
        return parent[v] == v ? v : parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> color(n+1);
        for (int i = 1; i <= n; i++)
            cin >> color[i];

        vector<vector<int>> adj(n+1);
        vector<pair<int,int>> edges(m);
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v;
            edges[i] = {u, v};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DSU dsu(n);
        for (auto &e : edges) {
            int u = e.first, v = e.second;
            if (color[u] == color[v])
                dsu.union_set(u, v);
        }

        vector<int> root_x(n+1), comp_sz(n+1, 0);
        for (int v = 1; v <= n; v++) {
            root_x[v] = dsu.find_set(v);
        }
        for (int v = 1; v <= n; v++) {
            if (root_x[v] == v)  
                comp_sz[v] = dsu.sz[v];
        }

        int ans = 0;
        for (int v = 1; v <= n; v++) {
            if (root_x[v] == v)
                ans = max(ans, comp_sz[v]);
        }

        vector<int> seen_root(n+1, 0);
        vector<int> seen_color(n+1, 0);
        vector<int> sum_color(n+1, 0);
        vector<int> active_colors;
        active_colors.reserve(64);

        int iter = 1;

        for (int x = 1; x <= n; x++, iter++) {
            active_colors.clear();
            int rx = root_x[x];
            for (int u : adj[x]) {
                int r = root_x[u];
                if (r == rx || seen_root[r] == iter) 
                    continue;
                seen_root[r] = iter;

                int c = color[u];
                if (seen_color[c] != iter) {
                    seen_color[c] = iter;
                    sum_color[c] = comp_sz[r];
                    active_colors.push_back(c);
                } else {
                    sum_color[c] += comp_sz[r];
                }
            }

            for (int c : active_colors) {
                ans = max(ans, sum_color[c] + 1);
                sum_color[c] = 0;  
            }
        }

        cout << ans << "\n";
    }
    return 0;
}