#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Line {
    int l, r, w;
    Line(int x, int y, int z) : l(x), r(y), w(z) {}
    Line() {}
    friend bool operator<(const Line &x, const Line &y) {
        return tie(x.l, x.r, x.w) < tie(y.l, y.r, y.w);
    }
};

struct Node {
    long long value = 0; // Initialize with a large negative value (neutral for max query)
    long long lazy = 0;          // Lazy value (initially 0)
};

const int MAXN = 1e6 + 5;
Node seg[4 * MAXN];
vector<pair<int, int>> intervals[MAXN];

// Propagate updates to children if the node has a pending lazy update
void propagate(int l, int r, int id) {
    if (seg[id].lazy) {
        seg[id].value += seg[id].lazy;
        if (l < r) {  // Propagate to children if not a leaf
            seg[id * 2].lazy += seg[id].lazy;
            seg[id * 2 + 1].lazy += seg[id].lazy;
        }
        seg[id].lazy = 0;  // Reset lazy value after propagation
    }
}

// Merge function to track the minimum value
Node merge(const Node &left, const Node &right) {
    Node result;
    result.value = min(left.value, right.value);
    return result;
}

// Update segment tree range with lazy propagation
void update(int l, int r, int v, int tl, int tr, int id) {
    propagate(tl, tr, id);  // Ensure node is updated before proceeding
    if (r < tl || tr < l) return;  // No overlap
    if (l <= tl && tr <= r) {  // Total overlap
        seg[id].lazy += v;
        propagate(tl, tr, id);
        return;
    }
    int mid = (tl + tr) / 2;
    update(l, r, v, tl, mid, id * 2);         // Update left child
    update(l, r, v, mid + 1, tr, id * 2 + 1); // Update right child
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]); // Merge results
}

// Query the maximum in a given range with lazy propagation
Node query(int l, int r, int tl, int tr, int id) {
    propagate(tl, tr, id);  // Ensure current node is up-to-date
    if (r < tl || tr < l) return Node();  // No overlap
    if (l <= tl && tr <= r) return seg[id];  // Total overlap
    int mid = (tl + tr) / 2;
    return merge(query(l, r, tl, mid, id * 2), query(l, r, mid + 1, tr, id * 2 + 1));
}

Line lines[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef ONLINE_JUDGE
    freopen("sseq.inp", "r", stdin);
    freopen("sseq.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        lines[i] = Line(x, y, z);
        intervals[lines[i].r].emplace_back(lines[i].l, lines[i].w);
    }
    sort(lines + 1, lines + 1 + n);
    
    int ans = 0;
    int pref = 0;
    for (int i = 1; i <= 1e6; ++i) {
        for (auto &j : intervals[i]) {
            update(j.first, i, j.second, 1, 1e6, 1);
            pref += j.second;
        }
        //cerr << pref << '\n';
        //cerr << i << '\n';
        //cerr << query(1, i, 1, 1e6, 1).value << '\n';
        ans = max(ans, pref);
        ans = max(ans, pref - query(1, i, 1, 1e6, 1).value);
    }
    
    cout << ans;
    return 0;
}
