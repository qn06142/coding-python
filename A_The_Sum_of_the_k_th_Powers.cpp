#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int64 modpow(int64 a, long long e){
    int64 r = 1 % MOD;
    a %= MOD;
    while(e){
        if(e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }
    return r;
}
int64 inv_mod(int64 x){
    return modpow((x%MOD+MOD)%MOD, MOD-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    int k;
    if(!(cin >> n >> k)) return 0;
    if(k == 0) {
        cout << n;
        return 0;
    }
    int m = k + 1;

    vector<int64> y(m+1);
    y[0] = 0;
    for(int i = 1; i <= m; ++i){
        y[i] = y[i-1] + modpow(i, k);
        if(y[i] >= MOD) y[i] -= MOD;
    }

    if(n <= m){
        cout << (y[n] % MOD + MOD) % MOD << '\n';
        return 0;
    }

    vector<int64> fact(m+1), invfact(m+1);
    fact[0] = 1;
    for(int i = 1; i <= m; ++i) fact[i] = fact[i-1] * i % MOD;
    invfact[m] = inv_mod(fact[m]);
    for(int i = m; i >= 1; --i) invfact[i-1] = invfact[i] * i % MOD;

    vector<int64> pref(m+2), suf(m+2);
    pref[0] = 1;
    for(int i = 0; i <= m; ++i){
        int64 term = ( (n - i) % MOD + MOD ) % MOD;
        pref[i+1] = (__int128)pref[i] * term % MOD;
    }
    suf[m+1] = 1;
    for(int i = m; i >= 0; --i){
        int64 term = ( (n - i) % MOD + MOD ) % MOD;
        suf[i] = (__int128)suf[i+1] * term % MOD;
    }

    auto prod_except_i = [&](int i)->int64{

        int64 left = pref[i];        
        int64 right = suf[i+1];     
        return (__int128)left * right % MOD;
    };

    int64 ans = 0;
    for(int i = 0; i <= m; ++i){
        int64 numer = prod_except_i(i);
        int64 denom = (__int128)invfact[i] * invfact[m - i] % MOD; 
        if( (m - i) & 1 ) denom = (MOD - denom) % MOD; 
        int64 Li = (__int128)numer * denom % MOD;
        ans += (__int128)y[i] * Li % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    cout << (ans % MOD + MOD) % MOD << '\n';
}