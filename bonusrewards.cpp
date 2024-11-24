#include <iostream>
using namespace std;
#pragma GCC optimize("Ofast,fast-math")
const int MOD = 111539768;

long long power_mod(long long k, int p, int mod) {
    long long result = 1;
    long long base = k;
    while (p > 0) {
        if (p % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        p /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n, k, x, y, u, v;
    cin >> m >> n >> k >> x >> y >> u >> v;

    long long total_sum = 0;

    for (int i = x; i <= u; ++i) {
        for (int j = y; j <= v; ++j) {

            int index = (i - 1) * n + (j - 1);

            long long value = power_mod(k, index, MOD);

            total_sum = (total_sum + value) % MOD;
        }
    }

    cout << total_sum << endl;

    return 0;
}