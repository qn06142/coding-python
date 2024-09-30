#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) begin(v), end(v)
#define pi pair<ll, ll>
#define vi vector<ll>
using namespace std;
const ll mod = 123456789;
ll n;
string k;
pair<ll, ll> dp[10][100003];

ll bpow(ll n, ll k){
    ll res = 1;
    while(k){
        if(k & 1) res = res * n % mod;
        n = n * n % mod;
        k >>=1;
    } 
    return res;
}

pair<ll, ll> comb(pair<ll, ll> a, pair<ll, ll> b){
    ll p = bpow(10, b.first);
    p = p * a.second % mod;
    p = (p + b.second) % mod;
    return {(a.first + b.first)%82260072, p};
}

void pre(){
    for(ll i = 0; i < 10; i++) dp[i][0] = {1, i};
    for(ll j = 1; j <= 100001; j++){
        for(ll i = 0; i < 10; i++){
            // cerr << j << " " << i << "\n";
            if(i * 3 < 10){
                dp[i][j] = dp[i*3][j-1];
            }
            else{
                dp[i][j] = comb(dp[(i*3)/10][j-1], dp[(i*3)%10][j-1]);
            }
        }
    }
}

void print(pair<ll,ll> a){
    cout << a.first << " " << a.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    pre();
    // for(int i = 1; i <= 30; i++) print(dp[1][i]);
    while(t--){
        cin >> k >> n;
        pair<ll,ll> res = dp[(k.back() - '0')][n];
        for(int i = k.size() - 2; i >= 0; i--){
            res = comb(dp[k[i] - '0'][n],res);
        }
        cout << res.second << "\n";
    }
    return 0;
}