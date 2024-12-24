#include <bits/stdc++.h>
using namespace std;

long long ans = 1;

struct line {
    int l, r;
    int cnt; 
    bool operator<(const line &other) const {
        return tie(l, r, cnt) < tie(other.l, other.r, other.cnt);
    }
};

set<line> stor;

set<line>::iterator getstart(int l) {
    auto it = stor.lower_bound({l, -1, -1});
    if (it != stor.begin()) {
        it--;
    }
    if (it->r < l) it++;
    return it;
}

set<line>::iterator getend(int r) {
    auto it = stor.upper_bound({r, INT_MAX, -1});
    return it;
}

const int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void add(int l, int r) {
    int sum = 1;
    long long tmp = 1;
    auto beg = getstart(l);
    auto end = getend(r);

    if (beg != stor.end() && beg->r < l) beg++;
    if (end != stor.begin() && prev(end)->l > r) end--;

    for (auto i = beg; i != end; ++i) {
        sum += i->cnt;
        tmp = (tmp * i->cnt) % mod;
        l = min(l, i->l);
        r = max(r, i->r);
    }

    stor.erase(beg, end);

    ans = (ans * binpow(tmp, mod - 2)) % mod; 
    ans = (ans * sum) % mod;

    stor.insert({l, r, sum});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int l, r;
    cin >> l >> r;
    stor.insert({l, r, 1});
    cout << ans << '\n';

    for (int i = 2; i <= n; i++) {
        cin >> l >> r;
        add(l, r);
        cout << ans << '\n';
    }

    return 0;
}