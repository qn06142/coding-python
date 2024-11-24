#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long mod_inv(long long x, long long mod) {
    return mod_pow(x, mod - 2, mod);
}

int main() {
    long long a, n;
    cin >> a >> n;
    
    if (a == 1) {
        cout << n % MOD << endl;
    } else {
        long long numerator = mod_pow(a, n + 1, MOD) - a;
        if (numerator < 0) numerator += MOD; // Ensure it's positive
        long long denominator = mod_inv(a - 1, MOD);
        long long ans = (numerator * denominator) % MOD;
        cout << ans << endl;
    }
    
    return 0;
}
