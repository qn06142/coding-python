#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const long long MOD = 111539768;

long long m, n, k, x, y, u, v;

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long f(long long x) {
    if(x == 0) {
        return 1;
    } else if(x == 1) {
        return k;
    } else if(x % 2 == 1) {
        long long t = f(x / 2);
        return (t + (binpow(k, x / 2) * t) % MOD + binpow(k, x)) % MOD;
    } else if(x % 2 == 0) {
        long long t = f(x / 2);
        return (t + (binpow(k, x / 2) * t) % MOD) % MOD;
    }
    return 0; // To handle all control paths
}

long long sum_in_column(long long col, long long r1, long long r2) {
    long long start_value = binpow(k, (col - 1) * m + (r1 - 1));
    long long end_value = binpow(k, (col - 1) * m + (r2 - 1));
    if (r1 == r2) {
        return start_value;
    } else {
        return (start_value * (binpow(k, r2 - r1 + 1) - 1) % MOD) * binpow(k - 1, MOD - 2) % MOD;
    }
}

long long sum_in_submatrix(long long x, long long y, long long u, long long v) {
    long long total_sum = 0;
    for (long long col = y; col <= v; col++) {
        total_sum = (total_sum + sum_in_column(col, x, u)) % MOD;
    }
    return total_sum;
}

int main() {
    cin >> m >> n >> k >> x >> y >> u >> v;
    cout << sum_in_submatrix(x, y, u, v) << endl;
    return 0;
}