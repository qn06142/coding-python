#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 3e6 + 5;
long long fac[MAX], inv[MAX];

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = power(fac[i], MOD - 2);
    }
}

long long C(int n, int k) {
    if (k > n || k < 0) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    m *= 2;
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        res = (res + C(n, i) * C(m - 1, i - 1) % MOD) % MOD;
    }
    cout << res;
    return 0;
}
