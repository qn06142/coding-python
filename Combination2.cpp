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

long long nCr(long long n, long long r) {
    long long numerator = 1;
    for (long long i = 0; i < r; ++i)
        numerator = (numerator * (n - i)) % MOD;

    long long denominator = 1;
    for (long long i = 1; i <= r; ++i)
        denominator = (denominator * i) % MOD;

    return (numerator * pow_mod(denominator, MOD - 2)) % MOD;
}

int main() {
    long long n, k;
    cin >> n >> k;
    cout << nCr(n + k - 1, k - 1) << endl;
    return 0;
}
