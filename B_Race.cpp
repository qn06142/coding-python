#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge { int to; int w; };

int n;
ll K;
vector<vector<Edge>> g;
vector<int> sz;
vector<char> removed;
int answer = INT_MAX;

int calc_size(int u, int p) {
    sz[u] = 1;
    for (auto &e : g[u]) if (e.to != p && !removed[e.to])
        sz[u] += calc_size(e.to, u);
    return sz[u];
}

int find_centroid(int u, int p, int tot) {
    for (auto &e : g[u]) if (e.to != p && !removed[e.to]) {
        if (sz[e.to] * 2 > tot) return find_centroid(e.to, u, tot);
    }
    return u;
}

void collect(int u, int p, ll dist, int edges,
             vector<pair<ll,int>> &bucket, ll K_limit) {
    if (dist > K_limit) return;
    bucket.emplace_back(dist, edges);
    for (auto &e : g[u]) if (e.to != p && !removed[e.to])
        collect(e.to, u, dist + e.w, edges + 1, bucket, K_limit);
}

void solve_centroid(int c) {
    unordered_map<ll,int> best;
    best.reserve(1024);
    best.max_load_factor(0.7f);
    best[0] = 0;
    for (auto &e : g[c]) if (!removed[e.to]) {
        vector<pair<ll,int>> vec;
        vec.reserve(256);
        collect(e.to, c, e.w, 1, vec, K);
        for (auto &p : vec) {
            auto it = best.find(K - p.first);
            if (it != best.end()) answer = min(answer, p.second + it->second);
        }
        for (auto &p : vec) {
            auto it2 = best.find(p.first);
            if (it2 == best.end() || p.second < it2->second) best[p.first] = p.second;
        }
    }
}

void decompose(int entry) {
    int tot = calc_size(entry, -1);
    int c = find_centroid(entry, -1, tot);
    solve_centroid(c);
    removed[c] = 1;
    for (auto &e : g[c]) if (!removed[e.to]) decompose(e.to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> K)) return 0;
    vector<tuple<int,int,int>> edges;
    edges.reserve(n-1);
    int min_id = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, l; cin >> u >> v >> l;
        edges.emplace_back(u, v, l);
        min_id = min(min_id, min(u, v));
    }

    // if nodes are 1-based (min_id == 1) convert to 0-based; else assume already 0-based
    bool input_is_one_based = (min_id == 1);
    g.assign(n, {});
    for (auto &t : edges) {
        int u, v, l; tie(u, v, l) = t;
        if (input_is_one_based) { --u; --v; }
        g[u].push_back({v, l});
        g[v].push_back({u, l});
    }

    sz.assign(n, 0);
    removed.assign(n, 0);

    if (K == 0) { cout << -1 << '\n'; return 0; }

    decompose(0);

    if (answer == INT_MAX) answer = -1;
    cout << answer << '\n';
    return 0;
}
