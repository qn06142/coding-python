#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    int maxN = N;
    vector<long long> fact(maxN + 1, 1), invFact(maxN + 1, 1);

    // Tính giai thừa và nghịch đảo giai thừa
    for (int i = 2; i <= maxN; i++) fact[i] = fact[i - 1] * i % MOD;
    invFact[maxN] = power(fact[maxN], MOD - 2, MOD);
    for (int i = maxN - 1; i >= 1; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;

    // Tính tổng điểm
    long long total = 0;
    for (int k = 1; k <= N - 1; k++) {
        long long Ck = fact[N - 1] * invFact[k] % MOD * invFact[N - 1 - k] % MOD;
        long long term = Ck * fact[N - 1 - k] % MOD * k % MOD;
        total = (total + term) % MOD;
    }

    cout << total << endl;
    return 0;
}
