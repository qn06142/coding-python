#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int FULL = (1 << m) - 1;
    int SZ = 1 << m;

    vector<int> freq(SZ, 0);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        int mask = 0;
        for(int j = 0; j < k; ++j){
            int x; cin >> x; 
            mask |= 1 << (x - 1);
        }
        ++freq[mask];
    }

    vector<int> h = freq;
    for(int bit = 0; bit < m; ++bit){
        for(int mask = 0; mask < SZ; ++mask){
            if(mask & (1 << bit)) h[mask] += h[mask ^ (1 << bit)];
        }
    }

    vector<int64> pow2(n + 1);
    pow2[0] = 1;
    for(int i = 1; i <= n; ++i){
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }

    int64 ans = 0;
    for(int S = 0; S < SZ; ++S){
        int comp = FULL ^ S;
        int c = h[comp]; 
        int bits = __builtin_popcount((unsigned)S);
        int64 term = pow2[c];
        if(bits & 1) {
            ans -= term;
        } else {
            ans += term;
        }
        if(ans >= MOD) ans -= MOD;
        if(ans < 0) ans += MOD;
    }

    ans %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans << '\n';
}