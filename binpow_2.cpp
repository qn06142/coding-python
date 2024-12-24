#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

long long modular_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << modular_pow(a, modular_pow(b, c, MOD - 1), MOD) << endl;
    }
    return 0;
}
