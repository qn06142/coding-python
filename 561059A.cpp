#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5 + 5, INF = 1e9 + 5;
int n, q;
int a[MAXN], ans[MAXN];

vector<int> st[MAXN * 4];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = {a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    merge(st[id * 2].begin(), st[id * 2].end(),
          st[id * 2 + 1].begin(), st[id * 2 + 1].end(),
          back_inserter(st[id]));
}

int query(int id, int l, int r, int ql, int qr, int v) {
    if (r < ql || l > qr) return INF;  
    if (ql <= l && r <= qr) {
        auto it = lower_bound(st[id].begin(), st[id].end(), v);
        if (it != st[id].end()) return *it;  
        return INF;  
    }
    int mid = (l + r) >> 1;
    return min(query(id * 2, l, mid, ql, qr, v),
               query(id * 2 + 1, mid + 1, r, ql, qr, v));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 1; i <= n * 4; ++i) {
        st[i].push_back(INF);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int cur = 0, res = 0;
        while (true) {

            int x = query(1, 1, n, l, r, cur * 2);
            if (x > 1e5) break;  
            res++;
            cur = x;  
        }
        cout << res << "\n";
    }

    return 0;
}