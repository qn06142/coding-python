#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;
struct Edge {int u, v, w;};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<char> is_exit(n+1, 0);
        for (int i = 0, e; i < k; i++) {
            cin >> e;
            is_exit[e] = 1;
        }
        vector<int> d(n+1);
        for (int i = 1; i <= n; i++) cin >> d[i];

        vector<Edge> edges(m);
        vector<vector<int>> adj_w(n+1);
        adj_w.reserve(n+1);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            adj_w[edges[i].u].push_back(edges[i].w);
            adj_w[edges[i].v].push_back(edges[i].w);
        }
        
        // Sort incident weights for each node for binary search
        for (int i = 1; i <= n; i++) {
            if (!adj_w[i].empty())
                sort(adj_w[i].begin(), adj_w[i].end());
        }

        // Build directed graph using safe-edge criterion: count_smaller >= d[i]
        vector<vector<pair<int,int>>> graph(n+1);
        graph.reserve(n+1);
        for (int i = 0; i < m; i++) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            auto &wu = adj_w[u];
            int cu = int(lower_bound(wu.begin(), wu.end(), w) - wu.begin());
            if (cu >= d[u])
                graph[u].emplace_back(v, w);
            auto &wv = adj_w[v];
            int cv = int(lower_bound(wv.begin(), wv.end(), w) - wv.begin());
            if (cv >= d[v])
                graph[v].emplace_back(u, w);
        }
        
        // Dijkstra from 1, stop early on any exit
        vector<ll> dist(n+1, INF);
        vector<char> vis(n+1, 0);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        dist[1] = 0;
        pq.emplace(0LL, 1);
        ll answer = -1;
        while (!pq.empty()) {
            auto [d_u, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            if (is_exit[u]) {
                answer = d_u;
                break;
            }
            for (auto &pr : graph[u]) {
                int v = pr.first;
                ll w = pr.second;
                if (vis[v]) continue;
                ll nd = d_u + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.emplace(nd, v);
                }
            }
        }
        
        cout << answer << '\n';
    }
    return 0;
}
