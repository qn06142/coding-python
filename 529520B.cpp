#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn (ll)(1e7 + 5)
#define mod (ll)(1e9 + 7)

ll f[maxn], sum, x, m;
ll i, n;

ll po(ll a, ll n) {
    ll res = a, ans = 1;
    while (n) {
        if (n % 2) ans = ans * res % mod;
        res = res * res % mod;
        n /= 2;
    }
    return ans;
}

ll C(ll n, ll k) {
    return f[n] * po(f[n - k], mod - 2) % mod * po(f[k], mod - 2) % mod;
}

int main() {
    f[0] = 1;

    for (i = 1; i < maxn; i++) f[i] = f[i - 1] * i % mod;

    cin >> m >> n;

    for (i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    if (m < sum) {
        cout << 0;
        return 0;
    }

    ll tmp, j;
    tmp = po(f[n - 1], mod - 2);  

    for (j = m - sum + 1; j <= m - sum + n - 1; j++) {
        tmp = (tmp * j) % mod;
    }

    cout << tmp;

    return 0;
}