#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int oo = 1000000099;
const int mod = 1000000007;
const int maxn = 5;

int n, ntest;

void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y){
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    ext_gcd(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

ll mul(ll a, ll b, ll mod){
    if(b == 0) return 0;
    ll res = mul(a, b / 2, mod);
    res = (res + res) % mod;
    if(b & 1) res = (res + a) % mod;
    return res;
}

bool cal(ll m1, ll a1, ll m2, ll a2, ll &m, ll &a){
    ll d, x, y;
    ext_gcd(m1, m2, d, x, y);
    if((a2 - a1) % d != 0) return 0;
    m = (m1 * m2) / d;
    ll t = m1 * (a2 - a1) / d;
    t = (t % m + m) % m;
    x = (x % m + m) % m;
    a = ((a1 + mul(t, x, m)) % m + m) % m;
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> ntest;
    ll a1, a2, a3, a4;
    ll m1, m2, m3, m4;
    cin >> m1 >> a1 >> m2 >> a2 >> m3 >> a3 >> m4 >> a4;
    ll m12, a12, m34, a34, m, a;
    if(!cal(m1, a1, m2, a2, m12, a12)){
        cout << "-1\n";
        return 0;
    }
    if(!cal(m3, a3, m4, a4, m34, a34)){
        cout << "-1\n";
        return 0;
    }
    if(!cal(m12, a12, m34, a34, m, a)){
        cout << "-1\n";
        return 0;
    }
    cout << a << "\n";
    return 0;
}
