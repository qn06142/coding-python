#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX = 2e5 + 2;
int n, a[MAX], pre[MAX];

struct SegmentTree {
    const int inf = INT_MAX;
    int tree[MAX * 4], lazy[MAX * 4];

    void init() {
        fill_n(tree + 1, n * 4, 0);
        fill_n(lazy + 1, n * 4, 0);
    }

    void pass(int id) {
        int t = lazy[id];
        lazy[id] = 0;
        tree[id * 2] += t; lazy[id * 2] += t;
        tree[id * 2 + 1] += t; lazy[id * 2 + 1] += t;
    }

    void rangeUpdate(int ql, int qr, int val, int id = 1, int l = 1, int r = n) {
        if (r < ql || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[id] += val;
            lazy[id] += val;
            return;
        }
        pass(id);
        int mid = (l + r) / 2;
        rangeUpdate(ql, qr, val, id * 2, l, mid);
        rangeUpdate(ql, qr, val, id * 2 + 1, mid + 1, r);
        tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
    }

    int rangeQuery(int ql, int qr, int id = 1, int l = 1, int r = n) {
        if (r < ql || qr < l) return inf;
        if (ql <= l && r <= qr) return tree[id];
        pass(id);
        int mid = (l + r) / 2;
        return min(rangeQuery(ql, qr, id * 2, l, mid), rangeQuery(ql, qr, id * 2 + 1, mid + 1, r));
    }
} tree;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        tree.init();
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            pre[i] = mp[a[i]];
            mp[a[i]] = i;
        }

        string ans = "YES\n";
        for (int i = 1; i <= n; ++i) {
            tree.rangeUpdate(pre[i] + 1, i, 1);
            if (pre[pre[i]] + 1 <= pre[i]) {
                tree.rangeUpdate(pre[pre[i]] + 1, pre[i], -1);
            }
            if (tree.rangeQuery(1, i) <= 0) {
                ans = "NO\n";
                break;
            }
        }

        cout << ans;
    }
}