#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll a, b, c;

void ext_gcd(ll a, ll b, ll &d, ll &x, ll & y){
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

int main(){
    cin >> a >> b >> c;
    ll d, x, y;
    ext_gcd(a, b, d, x, y);
    if(c % d != 0) return cout << 0, 0;
    ll lf, rt;
    if((c * x) % b == 0){
        lf = (-c * x) / b + 1;
    }
    else lf = (ll) ceil((-1.0 * c * x) / (1.0 * b));
    if((c * y) % a == 0){
        rt = (c * y) / a - 1;
    }
    else rt = (ll) floor((1.0 * c * y) / (1.0 * a));
    if(lf <= rt){
        cout << rt - lf + 1 << "\n";
    }
    else cout << 0 << "\n";
    return 0;
}