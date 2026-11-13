#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 200005;
const int maxq = 50005;

int n, q;
int a[maxn], sim[maxn];
pair<int, int> qr[maxq];
vector<int> vals[maxn], bit[maxn];

void add(int p, int v, int d) {
    while (p <= n) {
        int i = lower_bound(vals[p].begin(), vals[p].end(), v) - vals[p].begin() + 1;

        while (i < (int)bit[p].size()) {
            bit[p][i] += d;
            i += i & -i;
        }

        p += p & -p;
    }
}

int query(int p, int v) {
    int res = 0;

    while (p > 0) {
        int i = upper_bound(vals[p].begin(), vals[p].end(), v) - vals[p].begin();

        while (i > 0) {
            res += bit[p][i];
            i -= i & -i;
        }

        p -= p & -p;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        sim[i] = i;

        int p = i;
        while (p <= n) {
            vals[p].push_back(i);
            p += p & -p;
        }
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        if (l > r) {
            swap(l, r);
        }

        qr[i] = {l, r};

        if (l == r) {
            continue;
        }

        int p = l;
        while (p <= n) {
            vals[p].push_back(sim[r]);
            p += p & -p;
        }

        p = r;
        while (p <= n) {
            vals[p].push_back(sim[l]);
            p += p & -p;
        }

        swap(sim[l], sim[r]);
    }

    for (int i = 1; i <= n; i++) {
        sort(vals[i].begin(), vals[i].end());
        vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
        bit[i].resize(vals[i].size() + 1);
    }

    for (int i = 1; i <= n; i++) {
        a[i] = i;
        add(i, i, 1);
    }

    ll ans = 0;

    for (int i = 1; i <= q; i++) {
        int l = qr[i].first;
        int r = qr[i].second;

        if (l == r) {
            cout << ans << '\n';
            continue;
        }

        int u = a[l], v = a[r];

        int lo = min(u, v);
        int hi = max(u, v);

        int cnt = query(r - 1, hi - 1) - query(r - 1, lo) - query(l, hi - 1) + query(l, lo);

        if (u < v) {
            ans += 2LL * cnt + 1;
        } else {
            ans -= 2LL * cnt + 1;
        }

        add(l, u, -1);
        add(l, v, 1);
        add(r, v, -1);
        add(r, u, 1);

        swap(a[l], a[r]);

        cout << ans << '\n';
    }
}