#include <iostream>
#define MOD 1000000007

using namespace std;

long long modMul(long long a, long long b, long long mod) {
    return (a * b) % mod;
}

int main() {
    long long n, m;
    cin >> n >> m;

    long long rows = (n * (n + 1) / 2) % MOD;

    long long cols = (m * (m + 1) / 2) % MOD;

    long long result = modMul(rows, cols, MOD);

    cout << result << endl;

    return 0;
}