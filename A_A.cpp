#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h;
    cin >> n >> h;
    vector<int> a(n+1), need(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        need[i] = h - a[i];
        if (need[i] < 0 || need[i] > n) {
            cout << 0 << "\n";
            return 0;
        }
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        int want = need[i];
        for(int k = 0; k <= n; k++){
            ll ways = dp[i-1][k];
            if (!ways) continue;
            for(int starts = 0; starts <= 1; starts++){
                if (k + starts != want) continue;  
                int tbc = k + starts;
                for(int ends = 0; ends <= 1; ends++){
                    if (ends > tbc) break;
                    int j = tbc - ends;
                    ll factor = (ends == 1
                                 ? tbc  
                                 : 1LL);
                    dp[i][j] = (dp[i][j] + ways * factor) % MOD;
                }
            }
        }
    }
    cout << dp[n][0] << "\n";
}