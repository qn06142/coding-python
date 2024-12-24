#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 111539768;

long long mul(long long a, long long b, long long c) {
    if (b == 0) return 0;
    if (b == 1) return a % c;
    long long half = mul(a, b / 2, c);
    return (b % 2 == 0) ? (2 * half) % c : (2 * half + a) % c;
}

long long binpow(long long a, long long b, long long c) {
    if (b == 0) return 1;
    long long half = binpow(a, b / 2, c);
    long long result = mul(half, half, c);
    return (b % 2 == 0) ? result : mul(result, a, c);
}

long long calcrow(long long k, long long start, long long end) {
    long long length = end - start + 1;
    if (length == 1) return binpow(k, start, MOD);

    long long mid = start + length / 2 - 1;
    long long partialSum = calcrow(k, start, mid);

    if (length % 2 == 0) {
        return (partialSum + mul(partialSum, binpow(k, mid + 1 - start, MOD), MOD)) % MOD;
    } else {
        return (partialSum +
            mul(partialSum, binpow(k, mid + 1 - start, MOD), MOD) +
            binpow(k, end, MOD)) % MOD;
    }
}

long long calccol(long long k, long long start, long long end, long long n) {
    long long length = end - start + 1;
    if (length == 1) return binpow(k, start * n, MOD);

    long long mid = start + length / 2 - 1;
    long long partialSum = calccol(k, start, mid, n);

    if (length % 2 == 0) {
        return (partialSum + mul(partialSum, binpow(k, (mid + 1 - start) * n, MOD), MOD)) % MOD;
    } else {
        return (partialSum +
            mul(partialSum, binpow(k, (mid + 1 - start) * n, MOD), MOD) +
            binpow(k, end * n, MOD)) % MOD;
    }
}

void solve(long long m, long long n, long long k, long long x, long long y, long long u, long long v) {
    x--;
    y--;
    u--;
    v--;

    long long rows = calcrow(k, y, v);
    long long cols = calccol(k, x, u, n);

    cout << mul(rows, cols, MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long m, n, k, x, y, u, v;
    cin >> m >> n >> k >> x >> y >> u >> v;
    solve(m, n, k, x, y, u, v);

    return 0;
}