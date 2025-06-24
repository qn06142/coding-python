#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<u64> q(t);
    u64 maxm = 0;
    for(int i = 0; i < t; i++){
        cin >> q[i];
        maxm = max(maxm, q[i]);
    }

    int N = int(maxm + 2);
    vector<int> spf(N+1);
    for(int i = 2; i <= N; i++){
        if(!spf[i]){
            for(int j = i; j <= N; j += i){
                if(!spf[j]) spf[j] = i;
            }
        }
    }

    auto factor = [&](u64 x){
        unordered_map<u64,int> f;
        while(x > 1){
            u64 p = spf[x];
            int cnt = 0;
            while(x % p == 0){
                x /= p;
                cnt++;
            }
            f[p] += cnt;
        }
        return f;
    };

    for(u64 m : q){
        auto f1 = factor(m);
        auto f2 = factor(m+1);
        auto f3 = factor(m+2);
        for(auto & kv : f2) f1[kv.first] += kv.second;
        for(auto & kv : f3) f1[kv.first] += kv.second;
        __uint128_t D1 = 1, D2 = 1;
        for(auto & kv : f1){
            int e = kv.second;
            D1 *= (e + 1);
            D2 *= (2*e + 1);
        }
        __uint128_t tmp = D2 - 2*D1 + 1;
        u64 ans = u64(tmp / 2);
        cout << ans << "\n";
    }
}
