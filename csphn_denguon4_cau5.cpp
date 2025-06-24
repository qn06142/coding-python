
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll c;
    cin >> n >> c;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    ll hmax = *max_element(h.begin(), h.end()) + c;

    vector<ll> dp(hmax+1, INF), dp_cur(hmax+1, INF);

    for(ll x = h[0]; x <= hmax; x++){
        dp[x] = (x - h[0]) * (x - h[0]);
    }

    for(int i = 1; i < n; i++){

        vector<ll> best(hmax+1, INF);

        ll mn = INF;
        for(int x = 0; x <= hmax; x++){
            mn = min(mn + c, dp[x]);
            best[x] = mn;
        }

        mn = INF;
        for(int x = hmax; x >= 0; x--){
            mn = min(mn + c, dp[x]);
            best[x] = min(best[x], mn);
        }

        for(int x = 0; x <= hmax; x++){
            if (x < h[i]) {
                dp_cur[x] = INF;
            } else {
                ll lift = (x - h[i]) * (x - h[i]);
                dp_cur[x] = lift + best[x];
            }
        }
        swap(dp, dp_cur);
    }

    ll ans = INF;
    for(ll x = h[n-1]; x <= hmax; x++){
        ans = min(ans, dp[x]);
    }
    cout << ans << "\n";
}