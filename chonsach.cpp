#include <bits/stdc++.h>
using namespace std;

int c[2503], w[2503];
pair<int, int> a[2503];

bool cmp(pair<int, int> self, pair<int, int> other) {
    return self.first + self.second < other.first + other.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1; i <= n; i++) {
        a[i].first = w[i];
        a[i].second = c[i];
    }

    sort(a + 1, a + n + 1, cmp);

    vector<long long> dp(n + 1, LLONG_MAX);
    dp[0] = 0; 

    int res = 0;

    for (int i = 1; i <= n; i++) {
        int weight = a[i].first;
        int capacity = a[i].second;

        for (int h = res; h >= 0; h--) {

            if (dp[h] <= capacity) {
                dp[h + 1] = min(dp[h + 1], dp[h] + weight);
                res = max(res, h + 1); 
            }
        }
    }

    cout << res << "\n";
    return 0;
}