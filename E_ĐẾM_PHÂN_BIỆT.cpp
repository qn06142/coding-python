#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;
int n;
vector<int> adj[MAXN];
int color[MAXN];              
int origpos[MAXN];     

int tin[MAXN], tout[MAXN], toNode[MAXN], timer = 0;
int sz_arr[MAXN];

int l_, r_;

long long ans[MAXN];

struct Fenwick {
    int N;
    vector<int> bit;
    void init(int n) { N = n; bit.assign(n+5, 0); }
    void add(int idx, int val) { for (; idx <= N; idx += idx & -idx) bit[idx] += val; }
    long long sum(int idx) { long long r = 0; for (; idx > 0; idx -= idx & -idx) r += bit[idx]; return r; }
    long long range_sum(int l, int r) { if (r < l) return 0; return sum(r) - sum(l-1); }
} fenw;

void dfs(int u = 1, int p = 0) {
    tin[u] = ++timer;
    toNode[timer] = u;
    sz_arr[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        sz_arr[u] += sz_arr[v];
    }
    tout[u] = timer;
}

int cntc[MAXN];
int curuniq = 0;
int dval[MAXN];

inline void add(int node) {
    int c = color[node];
    if (++cntc[c] == 1) ++curuniq;
}
inline void rem(int node) {
    int c = color[node];
    if (--cntc[c] == 0) --curuniq;
}

void compd(int u, int p, bool keep) {
    int big = -1, best = 0;
    for (int v : adj[u]) if (v != p) {
        if (sz_arr[v] > best) { best = sz_arr[v]; big = v; }
    }
    for (int v : adj[u]) if (v != p && v != big) compd(v, u, false);
    if (big != -1) compd(big, u, true);

    for (int v : adj[u]) if (v != p && v != big) {
        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            add(x);
        }
    }

    add(u);
    dval[u] = curuniq;

    if (!keep) {

        for (int t = tin[u]; t <= tout[u]; ++t) {
            int x = toNode[t];
            rem(x);
        }
    }
}

inline long long qrang(int lo, int hi) {
    if (hi < lo) return 0;
    lo = max(lo, 1);           
    hi = min(hi, n);           
    if (lo > hi) return 0;
    return fenw.range_sum(lo, hi);
}

void dsu(int u, int p, bool keep) {
    int big = -1, best = 0;
    for (int v : adj[u]) if (v != p) {
        if (sz_arr[v] > best) { best = sz_arr[v]; big = v; }
    }
    for (int v : adj[u]) if (v != p && v != big) dsu(v, u, false);
    if (big != -1) dsu(big, u, true);

    long long total = 0;

    for (int v : adj[u]) if (v != p) total += ans[v];

    for (int v : adj[u]) if (v != p && v != big) {
        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];

            total += qrang(dval[x] - r_, dval[x] - l_);

            total += qrang(dval[x] + l_, dval[x] + r_);
        }

        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            fenw.add(dval[x], 1);
        }
    }

    total += qrang(dval[u] - r_, dval[u] - l_);   
    total += qrang(dval[u] + l_, dval[u] + r_);   

    if (l_ <= 0 && 0 <= r_) total += 1;

    fenw.add(dval[u], 1);

    ans[u] = total;

    if (!keep) {

        for (int t = tin[u]; t <= tout[u]; ++t) {
            int x = toNode[t];
            fenw.add(dval[x], -1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l_ >> r_;

    for (int i = 1; i <= n; ++i) {
        long long v; 
        cin >> v;
        origpos[i] = (int)v; 
    }

    vector<int> vals(n);
    for (int i = 0; i < n; ++i) vals[i] = origpos[i+1];
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 1; i <= n; ++i) {
        color[i] = int(lower_bound(vals.begin(), vals.end(), origpos[i]) - vals.begin()) + 1;
    }

    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer = 0;
    dfs(1, 0);

    for (int i = 0; i <= (int)vals.size() + 2; ++i) cntc[i] = 0;
    curuniq = 0;
    compd(1, 0, false);

    fenw.init(n + 5); 
    dsu(1, 0, false);

    for (int u = 1; u <= n; ++u) {
        cout << ans[u] << ' ';
    }

}