#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100005;
long long salary[MAXN];
vector<int> tree[MAXN];
int st[MAXN], en[MAXN];
int tour[MAXN], m = 0;

long long seg[4 * MAXN], lazy[4 * MAXN];

void dfs(int u, int parent_of_u) {
    tour[++m] = u;
    st[u] = m;

    for (int v : tree[u]) {
        if (v != parent_of_u) {
            dfs(v, u);
        }
    }

    en[u] = m;
}

void propagate(int idx, int l, int r) {
    if (lazy[idx] != 0) {
        seg[idx] += (r - l + 1) * lazy[idx];
        if (l != r) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update_range(int idx, int l, int r, int ql, int qr, long long value) {
    propagate(idx, l, r);
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        lazy[idx] += value;
        propagate(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_range(2 * idx, l, mid, ql, qr, value);
    update_range(2 * idx + 1, mid + 1, r, ql, qr, value);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

long long query_point(int idx, int l, int r, int pos) {
    propagate(idx, l, r);
    if (l == r) return seg[idx];
    int mid = (l + r) / 2;
    if (pos <= mid) return query_point(2 * idx, l, mid, pos);
    else return query_point(2 * idx + 1, mid + 1, r, pos);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int x;
    cin >> x;
    salary[1] = x;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        salary[i] = x;
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    dfs(1, 0); 

    for (int i = 1; i <= n; ++i) {
        update_range(1, 1, n, st[i], st[i], salary[i]);
    }

    while (m--) {
        char type;
        cin >> type;
        if (type == 'p') {
            int x, value;
            cin >> x >> value;

            if (st[x] + 1 <= en[x]) {
                update_range(1, 1, n, st[x] + 1, en[x], value);
            }
        } else if (type == 'u') {
            int x;
            cin >> x;
            cout << query_point(1, 1, n, st[x]) << '\n';
        }
    }

    return 0;
}