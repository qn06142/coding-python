#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll s1, s2;
    if (!(cin >> n >> s1 >> s2)) return 0;
    vector<ll> x(n+1);
    for (int i = 1; i <= n; ++i) cin >> x[i];

    auto feasible = [&](ll d)->bool {
        if (llabs(s1 - s2) > d) return false;

        set<ll> a, b; 
        if ( llabs(x[1] - s2) <= d ) a.insert(s2);
        if ( llabs(x[1] - s1) <= d ) b.insert(s1);
        if (a.empty() && b.empty()) return false;

        for (int i = 2; i <= n; ++i) {
            ll L = x[i] - d, R = x[i] + d;

            bool had_a = !a.empty();
            bool had_b = !b.empty();

            if (!a.empty()) {
                auto itl = a.lower_bound(L);
                if (a.begin() != itl) a.erase(a.begin(), itl);
                auto itr = a.upper_bound(R);
                if (itr != a.end()) a.erase(itr, a.end());
            }

            if (!b.empty()) {
                auto itl = b.lower_bound(L);
                if (b.begin() != itl) b.erase(b.begin(), itl);
                auto itr = b.upper_bound(R);
                if (itr != b.end()) b.erase(itr, b.end());
            }

            if (had_b && x[i-1] >= L && x[i-1] <= R) a.insert(x[i-1]);
            if (had_a && x[i-1] >= L && x[i-1] <= R) b.insert(x[i-1]);

            if (a.empty() && b.empty()) return false;
        }
        return true;
    };

    ll hi = 0;
    hi = max(hi, llabs(s1 - s2));
    for (int i = 1; i <= n; ++i) {
        hi = max(hi, llabs(x[i] - s1));
        hi = max(hi, llabs(x[i] - s2));
        if (i > 1) hi = max(hi, llabs(x[i] - x[i-1]));
    }
    ll lo = 0;

    if (hi < 0) hi = 0;

    while (lo < hi) {
        ll mid = (lo + hi) >> 1;
        if (feasible(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
    return 0;
}