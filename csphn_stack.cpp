#include <bits/stdc++.h>
using namespace std;
int c[(int) 2500 + 3], w[(int) 2500 + 3];
pair<int, int> a[(int) 2500 + 3];
bool cmp(pair<int, int> self, pair<int, int> other) {
    return self.first + self.second < other.first + other.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    int top = 0;
    for(int i = 1; i <= n; i++) {
        top += w[i];
        a[i].first = w[i];
        a[i].second = c[i];
    }
    sort(a + 1, a + n + 1, cmp);

    vector<int> dp(top + 1, 0);

    int res = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = min(top, a[i].first + a[i].second); j >= a[i].first; j--) {
            dp[j] = max(dp[j], dp[j - a[i].first] + 1);
            res = max(res, dp[j]);
        }
    }
    cout << res;
}
