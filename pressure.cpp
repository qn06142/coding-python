#include <bits/stdc++.h>
using namespace std;

const long long inf = 2e18;

struct Interval {
    int id;
    long long l, r, p;
};

int n;
long long m;
vector<Interval> a;
vector<long long> x;

struct SegTree {
    int sz;
    vector<long long> mn;
    vector<vector<pair<long long,int>>> v;

    void init(int n) {
        sz = n;
        mn.assign(4 * sz + 5, inf);
        v.assign(sz + 1, {});
    }

    void build(int p, int l, int r) {
        if (l == r) {
            mn[p] = v[l].empty() ? inf : v[l].back().first;
            return;
        }

        int mid = (l + r) / 2;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        mn[p] = min(mn[p * 2], mn[p * 2 + 1]);
    }

    void query(int p, int l, int r, int ql, int qr, long long mp, long long cr, vector<int>& z) {
        if (r < ql || qr < l || mn[p] > mp)
            return;

        if (l == r) {
            while (!v[l].empty() && v[l].back().first <= mp) {
                int id = v[l].back().second;
                v[l].pop_back();

                if (a[id].r > cr)
                    z.push_back(id);
            }

            mn[p] = v[l].empty() ? inf : v[l].back().first;
            return;
        }

        int mid = (l + r) / 2;
        query(p * 2, l, mid, ql, qr, mp, cr, z);
        query(p * 2 + 1, mid + 1, r, ql, qr, mp, cr, z);

        mn[p] = min(mn[p * 2], mn[p * 2 + 1]);
    }
} st;

bool check(long long k) {
    int sz = x.size();
    st.init(sz);

    for (int i = 0; i < n; i++) {
        if (a[i].p <= k) {
            int id = lower_bound(x.begin(), x.end(), a[i].l) - x.begin() + 1;
            st.v[id].push_back({a[i].p, i});
        }
    }

    for (int i = 1; i <= sz; i++)
        sort(st.v[i].begin(), st.v[i].end(),
            [](const pair<long long,int>& a, const pair<long long,int>& b) {
                return a.first > b.first;
            });

    st.build(1, 1, sz);

    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

    vector<long long> mr(n, inf);
    vector<int> z;

    int qr = upper_bound(x.begin(), x.end(), 1) - x.begin();

    if (qr) {
        st.query(1, 1, sz, 1, qr, k, 0, z);

        for (int i : z) {
            mr[i] = 0;
            pq.push({a[i].r, i});
        }
    }

    while (!pq.empty()) {
        long long cr = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cr >= m)
            return true;

        z.clear();

        int ql = upper_bound(x.begin(), x.end(), mr[u]) - x.begin() + 1;
        qr = upper_bound(x.begin(), x.end(), cr) - x.begin();

        if (ql <= qr)
            st.query(1, 1, sz, ql, qr, k - a[u].p, cr, z);

        int pos = lower_bound(x.begin(), x.end(), cr + 1) - x.begin();

        if (pos < sz && x[pos] == cr + 1)
            st.query(1, 1, sz, pos + 1, pos + 1, k, cr, z);

        for (int i : z) {
            mr[i] = cr;
            pq.push({a[i].r, i});
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    a.resize(n);

    for (int i = 0; i < n; i++) {
        a[i].id = i;
        cin >> a[i].l >> a[i].r >> a[i].p;
        x.push_back(a[i].l);
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    if (!check(2000000000LL)) {
        cout << -1 << '\n';
        return 0;
    }

    long long l = 1, r = 2000000000LL, ans = r;

    while (l <= r) {
        long long mid = (l + r) / 2;

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}