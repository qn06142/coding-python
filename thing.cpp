#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int maxm = 200005;

int n, m, cnt, timer;
int head[maxn], to[maxm * 2], nxt[maxm * 2];
int eu[maxm], ev[maxm];
int tin[maxn], low[maxn], par[maxn], pedge[maxn], iter[maxn];
int sz[maxn], root[maxn], stk[maxn];
bool bridge[maxm];

void add(int u, int v) {
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

int find(int u) {
    while (root[u] != u) {
        root[u] = root[root[u]];
        u = root[u];
    }
    return u;
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return;
    }

    if (sz[u] < sz[v]) {
        swap(u, v);
    }

    root[v] = u;
    sz[u] += sz[v];
}

void dfs(int s) {
    int top = 1;
    stk[top] = s;
    tin[s] = low[s] = ++timer;
    iter[s] = head[s];

    while (top) {
        int u = stk[top];

        if (!iter[u]) {
            top--;

            if (par[u]) {
                low[par[u]] = min(low[par[u]], low[u]);

                if (low[u] > tin[par[u]]) {
                    bridge[pedge[u]] = true;
                }
            }

            continue;
        }

        int e = iter[u];
        iter[u] = nxt[e];

        if ((e + 1) / 2 == pedge[u]) {
            continue;
        }

        int v = to[e];

        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            par[v] = u;
            pedge[v] = (e + 1) / 2;
            tin[v] = low[v] = ++timer;
            iter[v] = head[v];
            stk[++top] = v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> eu[i] >> ev[i];
        add(eu[i], ev[i]);
        add(ev[i], eu[i]);
    }

    for (int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;

        if (!tin[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (bridge[i]) {
            unite(eu[i], ev[i]);
        }
    }

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            ans += 1LL * (sz[i] - 1) * (sz[i] - 2) / 2;
        }
    }

    cout << ans;
}