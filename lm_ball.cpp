#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<ll> a(m), b(n);
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> L(m), R(m);
    for (int i = 0; i < m; ++i) {
        L[i] = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
        R[i] = int(b.end() - upper_bound(b.begin(), b.end(), a[i]));
    }

    int maxk = min(m, n / 2);
    int lo = 0, hi = maxk, ans = 0;
    auto can = [&](int k)->bool {
        if (k == 0) return true;
        int taken = 0; 
        for (int i = 0; i < m; ++i) {

            if (L[i] >= taken + 1 && R[i] >= (k - taken)) {
                ++taken;
                if (taken == k) return true;
            }
        }
        return false;
    };

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (can(mid)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }

    cout << ans << '\n';
    return 0;
}