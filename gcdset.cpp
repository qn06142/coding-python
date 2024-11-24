#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int query() {
    ll n, k;
    cin >> n >> k;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x % k == 0)
            res = __gcd(res, x / k);
    }

    return cout << (res == 1 ? "YES\n" : "NO\n"), 0;
}
int main () {
    int x;
    cin >> x;
    while(x--) {
        query();
    }
}