#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct SegmentTree {
    int n;
    vector<int> st;
    SegmentTree(int _n) : n(_n) {
        st.assign(4*n+4, INF);
    }
    void build(int p, int l, int r, const vector<int>& pos) {
        if (l == r) {
            st[p] = pos[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p<<1, l, m, pos);
        build(p<<1|1, m+1, r, pos);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }
    int query_min(int p, int l, int r, int i, int j) {
        if (r < i || l > j) return INF;
        if (l >= i && r <= j) return st[p];
        int m = (l + r) >> 1;
        return min(query_min(p<<1, l, m, i, j), query_min(p<<1|1, m+1, r, i, j));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, vector<int>> pos_map;
    pos_map.reserve(n*2);
    for (int i = 1; i <= n; i++) {
        pos_map[a[i]].push_back(i);
    }

    vector<int> next_k1(n+1, INF);
    for (auto &kv : pos_map) {
        auto &vec = kv.second;
        int sz = vec.size();
        for (int j = 0; j + k < sz; j++) {
            int idx = vec[j];
            next_k1[idx] = vec[j + k];
        }

    }

    SegmentTree st(n);
    st.build(1, 1, n, next_k1);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int min_pos = st.query_min(1, 1, n, l, r);

        if (min_pos <= r) cout << "No\n";
        else cout << "Yes\n";
    }
}
