#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("trapv")
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    ll n;
    cin >> t >> n;            

    int b = ceil(log2(n));
    int N = 1 << b;

    vector<ll> dp((1<<((long long)log2(n)+1)));
    for(int i = 1; i <= n; ++i){
        cin >> dp[i];
    }

    for(int bit = 0; bit < b; ++bit){
        for(int mask = 0; mask < N; ++mask){
            if(t == 1){

                if(mask & (1 << bit)){
                    dp[mask] += dp[mask ^ (1 << bit)];
                }
            } else {

                if(!(mask & (1 << bit))){
                    dp[mask] += dp[mask ^ (1 << bit)];
                }
            }
        }
    }

    for(int i=1;i<(1<<((long long)log2(n)+1));i++) cout << dp[i] << " ";

}