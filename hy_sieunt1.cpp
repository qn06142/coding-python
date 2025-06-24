#include <bits/stdc++.h>
using namespace std;
using u128 = unsigned __int128;

u128 mod_pow(u128 x, u128 y, u128 m) {
    u128 r = 1;
    while (y) {
        if (y & 1) r = (r * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return r;
}

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }
    long long d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    for (long long a : {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL}) {
        if (a % n == 0) continue;
        u128 x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; ++r) {
            x = (x * x) % n;
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    vector<int> seeds = {2, 3, 5, 7};
    long long ans = 0;

    function<void(long long)> dfs = [&](long long x) {
        if (x > b) return;
        if (x >= a and x >= 10) ans++;
        for (int d = 0; d <= 9; ++d) {
            long long y = x * 10 + d;
            if (y > b) continue;
            if (is_prime(y)) dfs(y);
        }
    };

    for (int p : seeds) {
        dfs(p);
    }

    cout << ans << "\n";
    return 0;
}
