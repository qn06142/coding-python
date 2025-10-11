#include <bits/stdc++.h>
using namespace std;

struct FastBIT {
    vector<int> f;
    inline void init(int n) { f.assign(n+1, 0); }
    inline void add(int i, int delta) {
        int N = (int)f.size();
        for (; i < N; i += i & -i) f[i] += delta;
    }
    inline int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    inline int range_sum(int l, int r) {
        if (r < l) return 0;
        return sum(r) - sum(l-1);
    }
};

int n, m;
vector<vector<int>> ys;      
vector<FastBIT> bits;        

void collect_y(int node, int l, int r, int x, int y) {
    ys[node].push_back(y);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid) collect_y(node<<1, l, mid, x, y);
    else collect_y(node<<1|1, mid+1, r, x, y);
}

void build_bits(int node, int l, int r) {
    if (!ys[node].empty()) {
        auto &v = ys[node];
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        bits[node].init((int)v.size());
    } else {
        bits[node].init(0);
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    build_bits(node<<1, l, mid);
    build_bits(node<<1|1, mid+1, r);
}

inline void point_add(int node, int l, int r, int x, int y, int delta) {
    auto &vec = ys[node];
    if (!vec.empty()) {
        int idx = int(lower_bound(vec.begin(), vec.end(), y) - vec.begin()) + 1; 

        bits[node].add(idx, delta);
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid) point_add(node<<1, l, mid, x, y, delta);
    else point_add(node<<1|1, mid+1, r, x, y, delta);
}

int query_rect(int node, int l, int r, int ql, int qr, int yl, int yr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) {
        auto &vec = ys[node];
        if (vec.empty()) return 0;
        int L = int(lower_bound(vec.begin(), vec.end(), yl) - vec.begin()) + 1;
        int R = int(upper_bound(vec.begin(), vec.end(), yr) - vec.begin());
        if (L > R) return 0;
        return bits[node].range_sum(L, R);
    }
    int mid = (l + r) >> 1;
    return query_rect(node<<1, l, mid, ql, qr, yl, yr)
         + query_rect(node<<1|1, mid+1, r, ql, qr, yl, yr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;
    vector<int> a(n+1), b_init(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b_init[i];

    struct Op { int t, x, y, la, ra, lb, rb; };
    vector<Op> ops;
    ops.reserve(m);
    for (int i = 0; i < m; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int la, ra, lb, rb; cin >> la >> ra >> lb >> rb;
            ops.push_back({t,0,0,la,ra,lb,rb});
        } else {
            int x, y; cin >> x >> y;
            ops.push_back({t,x,y,0,0,0,0});
        }
    }

    vector<int> posA(n+1);
    for (int i = 1; i <= n; ++i) posA[a[i]] = i;

    vector<vector<int>> ys_for_x(n+1);

    vector<int> b_sim = b_init;
    vector<int> posB_sim(n+1);
    for (int i = 1; i <= n; ++i) posB_sim[b_sim[i]] = i;

    for (int v = 1; v <= n; ++v) {
        int x = posA[v];
        int y = posB_sim[v];
        ys_for_x[x].push_back(y);
    }

    for (auto &op : ops) {
        if (op.t == 2) {
            int x_pos = op.x;
            int y_pos = op.y;
            if (x_pos == y_pos) continue;
            int v1 = b_sim[x_pos];
            int v2 = b_sim[y_pos];
            int p1 = posA[v1];
            int p2 = posA[v2];

            ys_for_x[p1].push_back(y_pos);
            ys_for_x[p2].push_back(x_pos);

            swap(b_sim[x_pos], b_sim[y_pos]);
        }
    }

    ys.assign(4*n + 5, {});
    bits.assign(4*n + 5, FastBIT());

    for (int x = 1; x <= n; ++x) {

        auto &vec = ys_for_x[x];
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        for (int y : vec) collect_y(1, 1, n, x, y);
    }

    build_bits(1, 1, n);

    vector<int> b = b_init;
    vector<int> posB(n+1);
    for (int i = 1; i <= n; ++i) posB[b[i]] = i;

    for (int v = 1; v <= n; ++v) {
        int x = posA[v];
        int y = posB[v];
        point_add(1, 1, n, x, y, +1);
    }

    for (auto &op : ops) {
        if (op.t == 1) {
            int la = op.la, ra = op.ra, lb = op.lb, rb = op.rb;
            cout << query_rect(1, 1, n, la, ra, lb, rb) << '\n';
        } else {
            int x_pos = op.x, y_pos = op.y;
            if (x_pos == y_pos) continue;
            int v1 = b[x_pos];
            int v2 = b[y_pos];
            int p1 = posA[v1];
            int p2 = posA[v2];

            point_add(1, 1, n, p1, x_pos, -1);
            point_add(1, 1, n, p2, y_pos, -1);

            point_add(1, 1, n, p1, y_pos, +1);
            point_add(1, 1, n, p2, x_pos, +1);

            swap(b[x_pos], b[y_pos]);
            posB[v1] = y_pos;
            posB[v2] = x_pos;
        }
    }
}