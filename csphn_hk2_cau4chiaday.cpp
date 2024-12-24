#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;
#define int long long

int maxsum(const vector<int>& a, int m) {
    int n = a.size();
    vector<int> dp(n + 1, 1e18);
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        deque<pair<int, int>> dq; 
        for (int j = i; j >= 1; --j) {

            if (prefix[i] - prefix[j - 1] > m) break;

            while (!dq.empty() && dq.front().second < j) dq.pop_front(); 
            while (!dq.empty() && dq.back().first <= a[j - 1]) dq.pop_back();
            dq.push_back({a[j - 1], j});

            dp[i] = min(dp[i], dp[j - 1] + dq.front().first);
        }
    }

    return dp[n] == 1e18 ? -1 : dp[n];
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << maxsum(a, m) << endl;
    }
}