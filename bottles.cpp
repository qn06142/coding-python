#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[(int) 1e6 + 5];
long long dp[(int) 1e6 + 5], pref[(int) 1e6 + 5];
int n, k;

int cal_value(int i) {
    return (i == 1 ? 0 : dp[i - 2]) - pref[i - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    k--;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    dp[0] = 0;
    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        int val = cal_value(i);
        while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
        while(!dq.empty() && cal_value(dq.back()) < val) dq.pop_back();
        dq.push_back(i);
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], cal_value(dq.front()) + pref[i]);
    }

    long long ans = dp[n];
    cout << ans << endl;

    return 0;
}
