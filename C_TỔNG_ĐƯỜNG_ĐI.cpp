#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;
int n;
vector<int> g[N];
int tin[N], tout[N], toNode[N], dep[N], timr;
int col[N];
long long ans;
vector<long long> cnt, sumd;

void dfs(int u = 1, int p = 0) {
    tin[u] = ++timr;
    toNode[timr] = u;
    for (int v : g[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    tout[u] = timr;
}

inline int subsz(int u) { return tout[u] - tin[u] + 1; }

void dsu(int u = 1, int p = 0, bool keep = 0) {
    int big = -1, best = 0;
    for (int v : g[u]) if (v != p) {
        int s = subsz(v);
        if (s > best) best = s, big = v;
    }

    for (int v : g[u]) if (v != p && v != big) dsu(v, u, 0);
    if (big != -1) dsu(big, u, 1);

    for (int v : g[u]) if (v != p && v != big) {
        for (int t = tin[v]; t <= tout[v]; t++) {
            int x = toNode[t], c = col[x];
            ans += cnt[c] * (dep[x] - 2LL * dep[u]) + sumd[c];
        }        
        for (int t = tin[v]; t <= tout[v]; t++) {
            int x = toNode[t], c = col[x];
            cnt[c]++; sumd[c] += dep[x];
        }
    }
    {
        int c = col[u];
        ans += sumd[c] - cnt[c] * 1LL * dep[u];
        cnt[c]++; sumd[c] += dep[u];
    }

    if (!keep)
        for (int t = tin[u]; t <= tout[u]; t++) {
            int x = toNode[t], c = col[x];
            cnt[c]--; sumd[c] -= dep[x];
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> col[i];

    dfs(1, 0);
    cnt.assign(200001, 0);
    sumd.assign(200001, 0);

    ans = 0;
    dsu(1, 0, 0);

    cout << ans << "\n";
}