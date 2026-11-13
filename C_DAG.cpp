#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
const int logn = 19;

int n, m;
vector<int> adj[maxn];
int d[maxn], dep[maxn], up[maxn][logn];

int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);

    for (int k = logn - 1; k >= 0; k--)
        if (dep[u] - (1 << k) >= dep[v])
            u = up[u][k];

    if (u == v)
        return u;

    for (int k = logn - 1; k >= 0; k--) {
        if (up[u][k] != up[v][k]) {
            u = up[u][k];
            v = up[v][k];
        }
    }

    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    d[1] = 0;
    dep[1] = 0;

    for (int k = 0; k < logn; k++)
        up[1][k] = 1;

    for (int i = 2; i <= n; i++) {
        for (int u : adj[i])
            d[i] = max(d[i], d[u] + 1);

        int p = -1;

        for (int u : adj[i]) {
            if (d[u] + 1 == d[i]) {
                if (p == -1)
                    p = u;
                else
                    p = lca(p, u);
            }
        }

        dep[i] = dep[p] + 1;
        up[i][0] = p;

        for (int k = 1; k < logn; k++)
            up[i][k] = up[up[i][k - 1]][k - 1];
    }

    for (int i = 1; i <= n; i++)
        cout << dep[i] << (i == n ? '\n' : ' ');
}
