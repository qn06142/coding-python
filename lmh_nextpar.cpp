#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // optional: validate non-decreasing input
    // for (int i = 2; i <= n; ++i) if (a[i] < a[i-1]) { cerr << "input not non-decreasing\n"; }

    vector<ll> pref(n+1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + a[i];
    ll S = pref[n];

    // Try to find the earliest index from right where we can increase a[i]
    for (int i = n-1; i >= 1; --i) {
        ll P = pref[i-1];            // sum of 1..i-1
        int t = n - i + 1;           // length of block i..n
        ll x = a[i] + 1;             // minimal increase to make b > a at position i

        // Condition: total sum available for positions i..n is S - P
        // Each of the t positions must be >= x, so need S - P >= x * t
        if (S - P >= x * (ll)t) {
            vector<ll> b(n+1);
            // copy prefix unchanged
            for (int k = 1; k <= i-1; ++k) b[k] = a[k];
            // set b[i..n-1] = x, put remainder in b[n]
            for (int k = i; k <= n-1; ++k) b[k] = x;
            b[n] = S - P - x * (t - 1); // remainder goes to last position

            // sanity: ensure non-decreasing and lexicographically greater
            // (should hold by construction)
            for (int k = 1; k <= n; ++k) cout << b[k] << (k==n?'\n':' ');
            return 0;
        }
        // else try earlier position (smaller i)
    }

    // If we reach here, no valid next array exists
    cout << -1 << '\n';
    return 0;
}
