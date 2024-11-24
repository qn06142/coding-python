#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2e5;

vector<int> compress(vector<int>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

long long add(long long a, long long b) {
    return (a + b >= MOD) ? a + b - MOD : a + b;
}

long long mul(long long a, long long b) {
    return (long long)a * b % MOD;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

class SegmentTree {
public:
    vector<pair<int, int>> st;

    void init(int n) {
        st.assign(4 * n + 2, {0, 0});
    }

    pair<int, int> merge(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first > b.first) return a;
        if (b.first > a.first) return b;
        return {a.first, add(a.second, b.second)};
    }

    void update(int node, int l, int r, int pos, pair<int, int> val) {
        if (l > pos || r < pos) return;
        if (l == r) {
            if (st[node].first < val.first) st[node] = val;
            else if (st[node].first == val.first) st[node].second = add(st[node].second, val.second);
        } else {
            int m = (l + r) >> 1;
            update(node * 2, l, m, pos, val);
            update(node * 2 + 1, m + 1, r, pos, val);
            st[node] = merge(st[node * 2], st[node * 2 + 1]);
        }
    }

    pair<int, int> query(int node, int l, int r, int u, int v) {
        if (l > v || r < u) return {0, 0};
        if (u <= l && r <= v) return st[node];
        int m = (l + r) >> 1;
        auto left = query(node * 2, l, m, u, v);
        auto right = query(node * 2 + 1, m + 1, r, u, v);
        return merge(left, right);
    }
};

SegmentTree st1, st2;
int n, a[MAXN + 2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> values;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        values.push_back(a[i]);
    }
    values = compress(values);

    int len = values.size();
    st1.init(len);
    st2.init(len);

    for (int i = 1; i <= n; ++i) {
        a[i] = upper_bound(values.begin(), values.end(), a[i]) - values.begin();
    }

    int max_length = 0, count = 0;
    for (int i = n; i >= 1; --i) {
        auto c1 = st1.query(1, 1, len, 1, a[i] - 1);
        auto c2 = st2.query(1, 1, len, a[i] + 1, len);

        if (c1.second < 1) c1.second = 1;
        if (c2.second < 1) c2.second = 1;

        if (max_length < c1.first + c2.first + 1) {
            max_length = c1.first + c2.first + 1;
            count = mul(c1.second, c2.second);
        } else if (max_length == c1.first + c2.first + 1) {
            count = add(count, mul(c1.second, c2.second));
        }

        c1.first++;
        c2.first++;
        st1.update(1, 1, len, a[i], c1);
        st2.update(1, 1, len, a[i], c2);
    }

    cout << max_length << ' ' << mul(count, binpow(2, n - max_length)) << '\n';
    return 0;
}
