#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int n;
int c[maxn];
vector<int> adj[maxn];

int tin[maxn], tout[maxn], toNode[maxn], timer = 0;
int dep[maxn];
long long ans = 0;

struct Fenwick {
    int N;
    vector<int> bit;
    Fenwick() : N(0) {}
    void init(int n) { N = n; bit.assign(n+1, 0); }
    void add(int idx, int val) { for (; idx <= N; idx += idx & -idx) bit[idx] += val; }
    long long sum(int idx) { long long r = 0; for (; idx > 0; idx -= idx & -idx) r += bit[idx]; return r; }
    long long range_sum(int l, int r) { if (r < l) return 0; return sum(r) - sum(l-1); }
} fenw;

void dfs(int u = 1, int p = 0) {
    tin[u] = ++timer;
    toNode[timer] = u;
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    tout[u] = timer;
}

inline int subsz(int u) { return tout[u] - tin[u] + 1; }

void dsu(int u = 1, int p = 0, bool keep = false) {
    int big = -1, bestSize = 0;
    for (int v : adj[u]) if (v != p) {
        int s = subsz(v);
        if (s > bestSize) { bestSize = s; big = v; }
    }

    for (int v : adj[u]) if (v != p && v != big) dsu(v, u, false);
    if (big != -1) dsu(big, u, true);

    for (int v : adj[u]) if (v != p && v != big) {
        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            long long limit = 1LL * c[x] - dep[x] + 2LL * dep[u];
            if (limit < 0) continue;
            if (limit > n) limit = n; 

            ans += fenw.sum((int)limit + 1);
        }

        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            fenw.add(dep[x] + 1, 1);
        }
    }

    {
        long long limit = 1LL * c[u] + dep[u];
        if (limit >= 0) {
            if (limit > n) limit = n;
            ans += fenw.sum((int)limit + 1);
        }
    }

    fenw.add(dep[u] + 1, 1);

    if (!keep) {
        for (int t = tin[u]; t <= tout[u]; ++t) {
            int x = toNode[t];
            fenw.add(dep[x] + 1, -1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dep[1] = 0;
    timer = 0;
    dfs(1, 0);

    fenw.init(n + 5);
    ans = 0;
    dsu(1, 0, false);

    ans += n;

    cout << ans << '\n';
}