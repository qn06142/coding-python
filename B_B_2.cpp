#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
const int MAX_N = 5e5 + 5;
const long long inf = 1e18;

int n, k, a[MAX_N], BIT[MAX_N];
pair<int, int> ST[MAX_N << 2];
int lazy[MAX_N << 2];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = {a[l], l};
    } else {
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
    }
}

void down(int id) {
    if (lazy[id]) {
        int k = lazy[id];
        ST[id << 1].fi -= k;
        ST[id << 1 | 1].fi -= k;
        lazy[id << 1] += k;
        lazy[id << 1 | 1] += k;
        lazy[id] = 0;
    }
}

void update_mark(int id, int l, int r, int i, int val) {
    if (l == r) {
        ST[id] = {val, i};
    } else {
        down(id);
        int mid = (l + r) >> 1;
        if (i <= mid) update_mark(id << 1, l, mid, i, val);
        else update_mark(id << 1 | 1, mid + 1, r, i, val);
        ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
    }
}

void update(int id, int l, int r, int u, int v, int val) {
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        ST[id].fi -= val;
        lazy[id] += val;
    } else {
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
    }
}

pair<int, int> get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return {inf, inf};
    if (u <= l && r <= v) return ST[id];
    down(id);
    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

void BIT_update(int idx, int val) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int BIT_get(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += BIT[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int BIT_getRange(int l, int r) {
    return BIT_get(r) - BIT_get(l - 1);
}

void process() {
    while (ST[1].fi <= k) {
        BIT_update(ST[1].se, 1);
        update_mark(1, 1, n, ST[1].se, inf);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    int numCase;
    cin >> numCase;
    while (numCase--) {
        char type;
        cin >> type;
        int l, r;
        cin >> l >> r;
        if (type == '1') {
            int x;
            cin >> x;
            update(1, 1, n, l, r, x);
        } else {
            process();
            cout << BIT_getRange(l, r) << '\n';
        }
    }

    return 0;
}
