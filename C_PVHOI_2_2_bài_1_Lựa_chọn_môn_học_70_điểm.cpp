#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<ll> e(n+1);
    for(int i=1;i<=n;i++) cin >> e[i];
    vector<ll> qs(m);
    for(int i=0;i<m;i++) cin >> qs[i];

    vector<vector<ll>> dp(n+2, vector<ll>(n+1, INF));
    dp[n+1][0] = 0;
    for(int i = n; i >= 1; --i){
        dp[i] = dp[i+1]; 
        for(int k = 1; k <= n; ++k){
            ll without = dp[i+1][k];
            ll need_next = dp[i+1][k-1];
            if(need_next >= INF/2){

                continue;
            }
            ll need_choose = max(-e[i], need_next - e[i]);
            if(need_choose < dp[i][k]) dp[i][k] = need_choose;
        }
    }

    vector<ll> need(n+1, INF);
    for(int k=0;k<=n;k++) need[k] = dp[1][k];

    for(int k=1;k<=n;k++) if(need[k] < need[k-1]) need[k] = need[k-1];

    for(int i=0;i<m;i++){
        ll s = qs[i];
        int k = upper_bound(need.begin(), need.end(), s) - need.begin() - 1;
        cout << k << ' ';
    }
}