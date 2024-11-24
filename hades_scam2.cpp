#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 4005;
const int maxh = 4005;
int a[maxn], n, d, c[maxn], dp[maxn][maxh + 3];

int calc(int i, int e) {
    return (i - e) * (i - e);
}

signed main() {
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = a[n];
    a[0] = a[1];
    int result = LLONG_MAX;
    memset(dp, 0x3f, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);

    for (int i = 1; i <= n; i++) {
        deque<int> dq1, dq2;

        for (int h = a[i]; h <= maxh; h++) {
            // Maintain deque1 for dp[h] - c[i-1] * h
            while (!dq1.empty() && dq1.front() < max(a[i - 1], h - d)) {
                dq1.pop_front();
            }
            while (!dq1.empty() && dp[i - 1][dq1.back()] - c[i - 1] * dq1.back() >= dp[i - 1][h] - c[i - 1] * h) {
                dq1.pop_back();
            }
            dq1.push_back(h);

            // Maintain deque2 for dp[h] + c[i-1] * h
            while (!dq2.empty() && dq2.front() < h) {
                dq2.pop_front();
            }
            while (!dq2.empty() && dq2.front() > min(maxh, h + d)) {
                dq2.pop_front();
            }
            while (!dq2.empty() && dp[i - 1][dq2.back()] + c[i - 1] * dq2.back() >= dp[i - 1][h] + c[i - 1] * h) {
                dq2.pop_back();
            }
            dq2.push_back(h);

            dp[i][h] = LLONG_MAX;

            if (!dq1.empty()) {
                dp[i][h] = min(dp[i][h], dp[i - 1][dq1.front()] - c[i - 1] * dq1.front() + c[i - 1] * h);
            }

            if (!dq2.empty()) {
                dp[i][h] = min(dp[i][h], dp[i - 1][dq2.front()] + c[i - 1] * dq2.front() - c[i - 1] * h);
            }

            dp[i][h] += calc(a[i], h);
        }
    }

    result = *min_element(dp[n] + a[n], dp[n] + 1 + maxh);
    cout << result << endl;
    return 0;
}