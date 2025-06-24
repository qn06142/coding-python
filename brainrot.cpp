#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n+1), S(n+1,0), dp(n+1,0), best(n+1,0), V(n+1,0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            S[i] = S[i-1] + a[i];
        }

        deque<int> dq;

        V[0] = 0;
        dq.push_back(0);

        for(int i = 1; i <= n; i++){

            while(!dq.empty() && dq.front() < i - k)
                dq.pop_front();

            ll bestV = dq.empty() ? LLONG_MIN/2 : V[dq.front()];
            ll dp_end = S[i] + bestV;

            dp[i] = max(dp[i-1], dp_end);
            best[i] = max(best[i-1], dp[i]);

            ll prev_best = (i - k >= 0 ? best[i - k] : 0);
            V[i] = prev_best - S[i];

            while(!dq.empty() && V[dq.back()] <= V[i])
                dq.pop_back();
            dq.push_back(i);
        }

        cout << dp[n] << "\n";
    }
    return 0;
}