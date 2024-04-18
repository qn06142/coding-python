#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int ntest;
ll a, b, c;

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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> ntest;
    while(ntest--){
        cin >> a >> b >> c;
        if(b < a) swap(a, b);
        ll d, x, y;
        ext_gcd(a, b, d, x, y);
        if(c % d != 0) cout << "-1\n";
        else{
            ll res = 1e18;
            // x >= 0 && y >= 0
            ll lf = ceil((-1.0 * c * x) / (1.0 * b));
            ll rt = floor((1.0 * c * y) / (1.0 * a));
            if(lf <= rt) res = (c / d) * (x + y) + (b - a) / d * lf;

            // x >= 0 && y <= 0
            lf = ceil((-1.0 * c * x) / (1.0 * b));
            rt = ceil((1.0 * c * y) / (1.0 * a));
            res = min(res, (c / d) * (x - y) + (b + a) / d * max(lf, rt));

            // x <= 0 && y >= 0
            lf = floor((-1.0 * c * x) / (1.0 * b));
            rt = floor((1.0 * c * y) / (1.0 * a));
            res = min(res, (c / d) * (y - x) - (b + a) / d * min(lf, rt));

            cout << res << "\n";
        }
    }
    return 0;
}
