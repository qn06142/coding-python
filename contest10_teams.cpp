#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());   

    vector<long long> pow2(n+1);
    pow2[0] = 1;
    for(int i = 1; i <= n; i++){
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }

    long long S = 0;

    for(int j = 1; j < n; j++){
        int ans = (n - 1) - j;  
        long long contri = ( a[j] % MOD ) * ( pow2[ans] ) % MOD;
        S = (S + contri) % MOD;
    }

    long long b1 = a[0] % MOD;
    long long ans = ( (2 * b1) % MOD * S ) % MOD;

    cout << ans << "\n";
}