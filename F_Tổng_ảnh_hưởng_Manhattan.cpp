#include <bits/stdc++.h>
using namespace std;

struct E {
    long long x, y, w;
    int tp, id, rw;
};

struct BIT {
    int n;
    vector<long long> c, s;

    BIT(int n = 0) {
        init(n);
    }

    void init(int n_) {
        n = n_;
        c.assign(n + 1, 0);
        s.assign(n + 1, 0);
    }

    void add(int p, long long x, long long y) {
        for (; p <= n; p += p & -p) {
            c[p] += x;
            s[p] += y;
        }
    }

    pair<long long,long long> qry(int p) {
        long long x = 0, y = 0;
        for (; p; p -= p & -p) {
            x += c[p];
            y += s[p];
        }
        return {x, y};
    }

    pair<long long,long long> qry(int l, int r) {
        if (l > r) return {0, 0};

        pair<long long,long long> a = qry(r);
        pair<long long,long long> b = qry(l - 1);

        return {a.first - b.first, a.second - b.second};
    }
};

bool sx;

bool cmpx(const E& a, const E& b) {
    if (a.x != b.x) return a.x < b.x;
    return sx ? a.tp > b.tp : a.tp < b.tp;
}

void cdq(int l, int r, bool sy, int m, vector<E>& e, vector<E>& t,
         BIT& bit, const vector<long long>& v, vector<long long>& ans) {
    if (l >= r) return;

    int mid = (l + r) / 2;

    cdq(l, mid, sy, m, e, t, bit, v, ans);
    cdq(mid + 1, r, sy, m, e, t, bit, v, ans);

    int p = l;

    for (int j = mid + 1; j <= r; j++) {
        if (e[j].tp != 1) continue;

        while (p <= mid) {
            bool ok = sy ? e[p].y < e[j].y : e[p].y <= e[j].y;
            if (!ok) break;

            if (e[p].tp == 0)
                bit.add(e[p].rw, 1, e[p].w);

            p++;
        }

        int pos = upper_bound(v.begin(), v.end(), e[j].w) - v.begin() + 1;

        if (pos <= m) {
            pair<long long,long long> z = bit.qry(pos, m);
            ans[e[j].id] += z.second - e[j].w * z.first;
        }
    }

    for (int i = l; i < p; i++) {
        if (e[i].tp == 0)
            bit.add(e[i].rw, -1, -e[i].w);
    }

    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r) {
        if (e[i].y <= e[j].y) t[k++] = e[i++];
        else t[k++] = e[j++];
    }

    while (i <= mid) t[k++] = e[i++];
    while (j <= r) t[k++] = e[j++];

    for (i = l; i <= r; i++)
        e[i] = t[i];
}

void solve(int ax, int ay, bool tx, bool ty,
           const vector<long long>& x1,
           const vector<long long>& y1,
           const vector<long long>& w1,
           const vector<long long>& x2,
           const vector<long long>& y2,
           vector<long long>& ans) {
    int n = x1.size();
    int q = x2.size();

    vector<E> e;
    vector<long long> v;

    e.reserve(n + q);
    v.reserve(n + q);

    for (int i = 0; i < n; i++) {
        long long x = ax * x1[i];
        long long y = ay * y1[i];
        long long w = x + y + w1[i];

        e.push_back({x, y, w, 0, -1, 0});
        v.push_back(w);
    }

    for (int i = 0; i < q; i++) {
        long long x = ax * x2[i];
        long long y = ay * y2[i];
        long long w = x + y;

        e.push_back({x, y, w, 1, i, 0});
        v.push_back(w);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int m = v.size();

    for (int i = 0; i < n + q; i++) {
        if (e[i].tp == 0)
            e[i].rw = lower_bound(v.begin(), v.end(), e[i].w) - v.begin() + 1;
    }

    sx = tx;
    sort(e.begin(), e.end(), cmpx);

    BIT bit(m);
    vector<E> t(n + q);

    cdq(0, n + q - 1, ty, m, e, t, bit, v, ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> x(n), y(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> w[i];

    vector<long long> qx(q), qy(q);
    for (int i = 0; i < q; i++)
        cin >> qx[i] >> qy[i];

    vector<long long> ans(q, 0);

    solve(1, 1, false, false, x, y, w, qx, qy, ans);
    solve(1, -1, false, true, x, y, w, qx, qy, ans);
    solve(-1, 1, true, false, x, y, w, qx, qy, ans);
    solve(-1, -1, true, true, x, y, w, qx, qy, ans);

    for (int i = 0; i < q; i++)
        cout << ans[i] << (i + 1 == q ? '\n' : ' ');
}