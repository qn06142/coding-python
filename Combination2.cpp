#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long pow_mod(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long comb(long long n, long long r) {
    long long tmp = 1;
    for (long long i = 0; i < r; ++i)
        tmp = (tmp * (n - i)) % MOD;

    long long tmp1 = 1;
    for (long long i = 1; i <= r; ++i)
        tmp1 = (tmp1 * i) % MOD;

    return (tmp * pow_mod(tmp1, MOD - 2)) % MOD;
}

int main() {
    long long n, k;
    cin >> k >> n;
    cout << comb(n + k - 1, n);
}
