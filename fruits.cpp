#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll res = 0;

    while(true) {
        ll sum = 0, count = 0;
        for(int i = 1; i <= n; i++) {
            if(m >= a[i]) {
                sum += a[i];
                res += 1;
                count += 1;
                m -= a[i];
            }
        }
        //cout << sum << endl;
        if(sum == 0) break;
        ll t = m / sum;
        //if(count == 0) break;
        res += t * count;
        m %= sum;
    }

    cout << res << "\n";

    return 0;
}
