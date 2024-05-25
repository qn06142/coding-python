#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 998244353;

int fact[N], inv[N], a[N], cnt[N], mx[N];

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = 1LL * res * a % mod;
        }
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    return 1LL * fact[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * i * fact[i - 1] % mod;
    }
    inv[N - 1] = power(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = 1LL * (i + 1) * inv[i + 1] % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[i] = 0;
            mx[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
            mx[a[i]] = max(mx[a[i]], cnt[a[i]]);
        }
        sort(a + 1, a + 1 + n);
        int ans = fact[n];
        if (mx[a[n]] > 1) {
            ans = 0;
        } else if (mx[a[n] - 1] + 1 == cnt[a[n]]) {
            for (int i = 1; i <= n; i++) {
                if (a[i] == a[n] - 1) {
                    ans = (ans - 1LL * fact[n - 1] * C(i, cnt[a[n] - 1]) % mod * fact[n - i] % mod + mod) % mod;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
