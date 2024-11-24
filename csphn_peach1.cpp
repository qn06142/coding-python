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
    if(b - a > 1e7) {
        vector<int> times;
        vector<pair<long long, long long>> peaches;

        for (int i = 0; i < n; ++i) {
            long long t, k;
            cin >> t >> k;
            if (t < b) {
                if(t >= a)
                times.push_back(t);
                peaches.push_back({t, k});
            }
        }
        times.push_back(b);
        times.push_back(a);
        sort(peaches.begin(), peaches.end());
        sort(times.begin(), times.end());
        times.resize(unique(times.begin(), times.end()) - times.begin());


        priority_queue<long long> pq;
        long long ans = 0;
        int j = 0;
        for(int i = 0; i < peaches.size(); i++) {
            if(peaches[i].first >= a) break;
            pq.push(peaches[i].second);
            peaches[i] = {0, 0};
        }
        for (int i = 0; i < times.size(); i++) {
            int curr = times[i];
            while (j < peaches.size() && (peaches[j].first == curr or peaches[j].first == 0)) {
                pq.push(peaches[j].second);
                ++j;
            }

            for(int x = times[i]; x < times[i + 1] && !pq.empty(); x++) {
                cerr << x << ' ';
                ans += pq.top();
                if(pq.top() == 0) {
                    x++;
                }
                pq.pop();
            }
        }

        cout << ans << "\n";
    } else {
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
    }
    return 0;
}
