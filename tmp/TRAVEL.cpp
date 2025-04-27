#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, W;
int v[MAXN], w[MAXN];

namespace Subtask1 {

    bool check() {
        return n <= 40;
    }
    vector<pair<int, int>> s1, s2;

    void bacctracc1(int l, int r, int wt, int val) {
        if(l > r) {
            s1.emplace_back(wt, val);
            return;
        }
        bacctracc1(l + 1, r, wt + w[l], val + v[l]);
        bacctracc1(l + 1, r, wt, val);
    }
    void bacctracc2(int l, int r, int wt, int val) {
        if(l > r) {
            s2.emplace_back(wt, val);
            return;
        }
        bacctracc2(l + 1, r, wt + w[l], val + v[l]);
        bacctracc2(l + 1, r, wt, val);
    }
    void solve() {
        int mid = n / 2;
        bacctracc1(1, mid, 0, 0);
        bacctracc2(mid + 1, n, 0, 0);

        sort(s2.begin(), s2.end());
        vector<pair<int,int>> filtered;
        int maxVal = -1;
        for(auto &p : s2) {
            if(p.second > maxVal) {
                filtered.push_back(p);
                maxVal = p.second;
            }
        }
        s2 = filtered;

        int ans = 0;

        for(auto &p : s1) {
            int rem = W - p.first;
            if(rem < 0) continue;
            int lo = 0, hi = s2.size() - 1, best = -1;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(s2[mid].first <= rem) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if(best != -1)
                ans = max(ans, p.second + s2[best].second);
        }
        cout << ans << "\n";
    }
}

namespace Subtask2 {
    bool check() {
        return (n > 40 && W <= 100000);
    }
    void solve() {

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                dp[i][j] = dp[i - 1][j];
                if(j >= w[i])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        cout << dp[n][W] << "\n";
    }
}

namespace Subtask3 {
    bool check() {
        return (n > 40 && W > 100000);
    }
    void solve() {
        int sumV = 0;
        for (int i = 1; i <= n; i++) {
            sumV += v[i];
        }
        const long long INF = 1e18;

        vector<long long> dp(sumV + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {

            for (int j = sumV - v[i]; j >= 0; j--) {
                if(dp[j] != INF) {
                    dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
                }
            }
        }
        int ans = 0;
        for (int x = 0; x <= sumV; x++) {
            if (dp[x] <= W) {
                ans = x;
            }
        }
        cout << ans << "\n";
    }
}

int main(){
    freopen("TRAVEL.INP", "r", stdin);
    freopen("TRAVEL.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    if (Subtask1::check()) {
        Subtask1::solve();
    } else if (Subtask2::check()) {
        Subtask2::solve();
    } else if (Subtask3::check()) {
        Subtask3::solve();
    }
    return 0;
}