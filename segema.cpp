#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll d;
    cin >> n >> d;
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i] - (ll)i * d;
    }

    sort(c.begin(), c.end());
    ll x = c[n/2];  // median (0-based)
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += llabs(c[i] - x);
    }
    cout << ans << "\n";
    return 0;
}
