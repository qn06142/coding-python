#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("arch=skylake")
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    long long a, b;
    cin >> n >> a >> b;

    vector<pair<long long, long long>> peaches;

    for (int i = 0; i < n; ++i) {
        long long t, k;
        cin >> t >> k;
        if (t <= b) {
            peaches.push_back({t, k});
        }
    }

    sort(peaches.begin(), peaches.end());

    priority_queue<long long> pq;
    long long ans = 0;
    int j = 0;

    for (long long curr = a; curr < b; ++curr) {

        while (j < peaches.size() && peaches[j].first <= curr) {
            pq.push(peaches[j].second);
            ++j;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
    return 0;
}
