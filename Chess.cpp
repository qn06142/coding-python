#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
const int maxq = 200000 + 5;

struct Edge {
    int u, v;
} e[maxn];

struct Query {
    int x, y, z;
    int l, r, ans;
} q[maxq];

int p[maxn], sz[maxn];
vector<int> at[maxn];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> q[i].x >> q[i].y >> q[i].z;
        q[i].l = 1;
        q[i].r = m;
        q[i].ans = m;
    }

    while (1) {
        bool ok = 0;

        for (int i = 1; i <= m; i++)
            at[i].clear();

        for (int i = 0; i < k; i++) {
            if (q[i].l <= q[i].r) {
                at[(q[i].l + q[i].r) >> 1].push_back(i);
                ok = 1;
            }
        }

        if (!ok) break;

        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }

        for (int i = 1; i <= m; i++) {
            unite(e[i].u, e[i].v);

            for (int id : at[i]) {
                int x = find(q[id].x);
                int y = find(q[id].y);

                int s = (x == y ? sz[x] : sz[x] + sz[y]);

                if (s >= q[id].z) {
                    q[id].ans = i;
                    q[id].r = i - 1;
                } else {
                    q[id].l = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << q[i].ans << '\n';
}