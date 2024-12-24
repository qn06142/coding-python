#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
long long pref[MAXN];
long long a[MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    unordered_map<int, long long> minpref;
    long long ans = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        if (minpref.count(a[i])) {
            ans = max(ans, pref[i] - minpref[a[i]]);
        } else {
            minpref[a[i]] = pref[i - 1];
        }
        minpref[a[i]] = min(minpref[a[i]], pref[i - 1]);
    }

    cout << ans << '\n';
    return 0;
}
