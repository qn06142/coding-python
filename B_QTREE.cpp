#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct Tracker {
    vector<int> cnt;
    priority_queue<int, vector<int>, greater<int>> pq;

    void init(int n) {
        cnt.assign(n + 1, 0);
        while (!pq.empty())
            pq.pop();
    }

    void add(int x) {
        if (!cnt[x])
            pq.push(x);
        cnt[x]++;
    }

    void del(int x) {
        cnt[x]--;
    }

    pair<int,int> get() {
        while (!pq.empty() && !cnt[pq.top()])
            pq.pop();

        if (pq.empty())
            return {-1, 0};

        return {pq.top(), cnt[pq.top()]};
    }
};

int n, m, q;
vector<int> adj[200005];
vector<bool> rm, ina;
vector<int> sz;
vector<pair<int,int>> anc[200005];
Tracker tr[200005];

int mx;

void getsz(int u, int p) {
    sz[u] = 1;

    for (int v : adj[u]) {
        if (v == p || rm[v])
            continue;

        getsz(v, u);
        sz[u] += sz[v];
    }
}

int getc(int u, int p, int tot) {
    for (int v : adj[u]) {
        if (v == p || rm[v])
            continue;

        if (sz[v] > tot / 2)
            return getc(v, u, tot);
    }

    return u;
}

void getdist(int u, int p, int d, int c) {
    anc[u].push_back({c, d});
    mx = max(mx, d);

    for (int v : adj[u]) {
        if (v == p || rm[v])
            continue;

        getdist(v, u, d + 1, c);
    }
}

void decomp(int u) {
    getsz(u, 0);
    int c = getc(u, 0, sz[u]);

    mx = 0;
    getdist(c, 0, 0, c);
    tr[c].init(mx);

    rm[c] = true;

    for (int v : adj[c]) {
        if (!rm[v])
            decomp(v);
    }
}

void toggle(int u) {
    if (!ina[u]) {
        ina[u] = true;

        for (pair<int,int> e : anc[u])
            tr[e.first].add(e.second);
    } else {
        ina[u] = false;

        for (pair<int,int> e : anc[u])
            tr[e.first].del(e.second);
    }
}

pair<int,int> query(int u) {
    int best = inf, cnt = 0;

    for (pair<int,int> e : anc[u]) {
        int c = e.first;
        int d = e.second;

        pair<int,int> z = tr[c].get();

        if (!z.second)
            continue;

        int cur = d + z.first;

        if (cur < best) {
            best = cur;
            cnt = z.second;
        } else if (cur == best) {
            cnt += z.second;
        }
    }

    return {best, cnt};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;

    rm.assign(n + 1, false);
    ina.assign(n + 1, false);
    sz.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decomp(1);

    for (int i = 1; i <= m; i++) {
        int u;
        cin >> u;
        toggle(u);
    }

    while (q--) {
        int t, u;
        cin >> t >> u;

        if (t == 1)
            toggle(u);
        else {
            pair<int,int> ans = query(u);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
}