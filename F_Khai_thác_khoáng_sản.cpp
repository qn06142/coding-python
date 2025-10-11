#include <bits/stdc++.h>
using namespace std;

const int MAXK = 5000;
const int MOD = 1000000007;

int n, q;
vector<vector<int>> g;
int a_val[5005];

int tin[5005], tout[5005], toNode[5005], timr;
int par[5005];

void dfs_order(int u = 1, int p = 0) {
    par[u] = p;
    tin[u] = ++timr;
    toNode[timr] = u;
    for (int v : g[u]) if (v != p) {
        dfs_order(v, u);
    }
    tout[u] = timr;
}

inline int subsz(int u) { return tout[u] - tin[u] + 1; }

vector<vector<pair<int,int>>> queries; 
vector<int> ans; 

vector< vector<int> > pref; 

vector<int>* recur(int u, int p) {

    int big = -1, best = 0;
    for (int v : g[u]) if (v != p) {
        int s = subsz(v);
        if (s > best) { best = s; big = v; }
    }

    vector<int>* base;
    if (big != -1) {

        base = recur(big, u);
    } else {

        base = new vector<int>(MAXK + 1, 0);
        (*base)[0] = 1; 
    }

    for (int v : g[u]) if (v != p && v != big) {
        vector<int>* tmp = recur(v, u); 

        for (int t = tin[v]; t <= tout[v]; ++t) {
            int x = toNode[t];
            int w = a_val[x];
            if (w > MAXK) continue;
            for (int s = MAXK; s >= w; --s) {
                int add = (*base)[s - w];
                if (add) {
                    (*base)[s] += add;
                    if ((*base)[s] >= MOD) (*base)[s] -= MOD;
                }
            }
        }
    }

    int wu = a_val[u];
    if (wu <= MAXK) {
        for (int s = MAXK; s >= wu; --s) {
            int add = (*base)[s - wu];
            if (add) {
                (*base)[s] += add;
                if ((*base)[s] >= MOD) (*base)[s] -= MOD;
            }
        }
    }

    pref[u].assign(MAXK + 1, 0);
    long long acc = 0;
    for (int s = 0; s <= MAXK; ++s) {
        acc += (*base)[s];
        if (acc >= MOD) acc -= MOD;
        pref[u][s] = (int)acc;
    }
    for (auto &qq : queries[u]) {
        int k = qq.first;
        int idx = qq.second;
        if (k > MAXK) k = MAXK;
        ans[idx] = pref[u][k];
    }

    return base;
}

int main() {
    cin >> n >> q;
    g.assign(n + 1, {});
    for (int i = 1; i <= n; ++i) {
        cin >> a_val[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queries.assign(n + 1, {});
    ans.assign(q, 0);
    for (int i = 0; i < q; ++i) {
        int u, k; cin >> u >> k;
        if (k > MAXK) k = MAXK; 
        queries[u].push_back({k, i});
    }

    timr = 0;
    dfs_order(1, 0);
    pref.assign(n + 1, vector<int>()); 

    vector<int>* root = recur(1, 0);

    for (int i = 0; i < q; ++i) {
        cout << ans[i] % MOD << "\n";
    }
}