#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long pw(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    long long s = 0;
    for (long long i = 0; i < n; i++)
        s = (s + pw(m, gcd(i, n))) % mod;

    cout << s * pw(n, mod - 2) % mod << '\n';
}