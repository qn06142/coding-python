#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll c;
    if(!(cin >> n >> c)) return 0;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    if(n == 1){
        cout << c << '\n';
        return 0;
    }

    int min_a = *min_element(a.begin(), a.end());
    int max_a = *max_element(a.begin(), a.end());
    int R = max_a - min_a + 1;

    vector<ll> best(R, INF);

    ll dp1 = c;
    for(int idx = 0; idx < R; ++idx){
        int x = min_a + idx;
        best[idx] = dp1 + 1LL * b[0] * x;
    }

    ll dp = dp1;
    for(int i = 1; i < n; ++i){
        int ai = a[i];
        int idx_ai = ai - min_a;
        ll dpi = best[idx_ai];
        dp = dpi;
        ll slope = b[i];
        ll intercept = dpi;
        for(int idx = 0; idx < R; ++idx){
            int x = min_a + idx;
            ll val = intercept + slope * 1LL * x;
            if(val < best[idx]) best[idx] = val;
        }
    }

    cout << dp << '\n';
    return 0;
}