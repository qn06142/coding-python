#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mn = 1e3 + 5;
const int INF = -1e9;
ll n, q, c[mn], d[mn], w, l, r;
vector<ll> st[4 * mn], spl, fck;

vector<ll> merge(const vector<ll>& a, const vector<ll>& b) {
    if (a.size() == 1) return b;
    if (b.size() == 1) return a;

    vector<ll> ret(a);
    for (int i = 1; i <= w; ++i) {
        for (int j = i; j <= w; ++j) {
            ret[j] = max(ret[j], a[j - i] + b[i]);
        }
    }
    return ret;
}

void build(ll l, ll r, ll ind) {
    if (l == r) {
        st[ind] = spl;
        st[ind][c[l]] = d[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(l, mid, ind * 2);
    build(mid + 1, r, ind * 2 + 1);
    st[ind] = merge(st[ind * 2], st[ind * 2 + 1]);
}

vector<ll> get(ll l, ll r, ll u, ll v, ll ind) {
    if (r < u || v < l) return fck;
    if (u <= l && r <= v) return st[ind];
    ll mid = (l + r) / 2;
    return merge(get(l, mid, u, v, ind * 2), get(mid + 1, r, u, v, ind * 2 + 1));
}

ll ans(const vector<ll>& a) {
    ll ret = 0;
    for (int i = 1; i <= w; ++i) ret = max(ret, a[i]);
    return ret;
}

void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
    }

    spl.assign(w + 2, INF); 
    spl[0] = 0; 

    fck.assign(w + 1, INF); 
    fck[0] = 0;
    build(1, n, 1);

    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << ans(get(1, n, l, r, 1)) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
