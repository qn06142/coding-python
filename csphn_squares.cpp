#include <iostream>
using namespace std;
#define int long long

const long long mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int countsquares(int m, int n) {
    if (m > n) swap(m, n);
    return n * (n + 1) * (3 * m - n + 1) * binpow(6, mod - 2, mod);
}

signed main() {
    int m, n;
    cin >> m >> n;
    cout << countsquares(m, n) << endl;
    return 0;
}
