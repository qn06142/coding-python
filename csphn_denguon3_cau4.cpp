#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }

    int M = 0;
    for (int i = 0; i < n; i++){
        M = max(M, h[i]);
    }

    const long long INF = 1LL << 60; 

    vector<long long> dp(M+1, INF), newdp(M+1, INF);

    for (int v = h[0]; v <= M; v++){
        dp[v] = (long long)(v - h[0]) * (v - h[0]);
    }

    for (int i = 1; i < n; i++){

        vector<long long> L(M+1, INF), R(M+1, INF);

        L[1] = dp[1];
        for (int v = 2; v <= M; v++){
            L[v] = min(dp[v], L[v-1] + c);
        }

        R[M] = dp[M];
        for (int v = M - 1; v >= 1; v--){
            R[v] = min(dp[v], R[v+1] + c);
        }

        for (int v = 1; v <= M; v++){
            long long best = min(L[v], R[v]);

            if(v < h[i])
                newdp[v] = INF;
            else
                newdp[v] = best + (long long)(v - h[i]) * (v - h[i]);
        }
        dp.swap(newdp);
    }

    long long ans = INF;
    for (int v = h[n-1]; v <= M; v++){
        ans = min(ans, dp[v]);
    }
    cout << ans;
    return 0;
}