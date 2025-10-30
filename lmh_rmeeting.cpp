#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n+1), radj(n+1);
    vector<pair<int,int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u); // reverse edge
        edges.emplace_back(u, v);
    }

    // For every target v compute dist_to_v[u] (shortest u->v) using BFS on reversed graph,
    // and compute gcd g_v of cycle-length-differences.
    vector<vector<int>> dist_to_v(n+1, vector<int>(n+1, INF)); // dist_to_v[v][u] = shortest u->v
    vector<int> g(n+1, 0);

    for (int v = 1; v <= n; ++v) {
        // BFS on radj from v
        queue<int> q;
        dist_to_v[v][v] = 0;
        q.push(v);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int y : radj[x]) {
                if (dist_to_v[v][y] == INF) {
                    dist_to_v[v][y] = dist_to_v[v][x] + 1;
                    q.push(y);
                }
            }
        }
        // compute gcd over edges where both endpoints can reach v
        int gv = 0;
        for (auto &e : edges) {
            int a = e.first, b = e.second;
            if (dist_to_v[v][a] != INF && dist_to_v[v][b] != INF) {
                int delta = dist_to_v[v][a] - (dist_to_v[v][b] + 1);
                if (delta != 0) {
                    gv = std::gcd(gv, abs(delta));
                }
            }
        }
        g[v] = gv; // may be 0
    }

    int qcount; cin >> qcount;
    while (qcount--) {
        int k; cin >> k;
        vector<int> starts(k);
        for (int i = 0; i < k; ++i) cin >> starts[i];

        long long answer = LLONG_MAX;
        // try each meeting vertex v
        for (int v = 1; v <= n; ++v) {
            bool ok = true;
            int gv = g[v];
            vector<int> dists;
            dists.reserve(k);
            for (int si : starts) {
                int d = dist_to_v[v][si];
                if (d == INF) { ok = false; break; }
                dists.push_back(d);
            }
            if (!ok) continue;

            if (gv == 0) {
                // all dists must be equal
                bool all_equal = true;
                for (int i = 1; i < (int)dists.size(); ++i)
                    if (dists[i] != dists[0]) { all_equal = false; break; }
                if (all_equal) {
                    answer = min<long long>(answer, dists[0]);
                }
                continue;
            } else {
                // all dists mod gv must be equal
                int r = ((dists[0] % gv) + gv) % gv;
                bool congr = true;
                int mx = dists[0];
                for (int i = 1; i < (int)dists.size(); ++i) {
                    if (((dists[i] % gv) + gv) % gv != r) { congr = false; break; }
                    mx = max(mx, dists[i]);
                }
                if (!congr) continue;
                // smallest T >= mx with T % gv == r
                int rem = ((mx % gv) + gv) % gv;
                int add = (r - rem + gv) % gv;
                long long T = (long long)mx + add;
                answer = min(answer, T);
            }
        }

        if (answer == LLONG_MAX) cout << -1 << '\n';
        else cout << answer << '\n';
    }

    return 0;
}
