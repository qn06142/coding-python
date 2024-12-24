#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;

long long fact[MAX], invFact[MAX];

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

void prep() {
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[MAX - 1] = modPow(fact[MAX - 1], MOD - 2, MOD); 
    for (int i = MAX - 2; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
    invFact[0] = 1;  
}

long long C(int a, int b) {
    if (b > a) return 0;
    return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
}

long long multinomial(int x, int y, int z) {
    long long total = x + y + z;
    return fact[total] * invFact[x] % MOD * invFact[y] % MOD * invFact[z] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    prep();

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << multinomial(x, y, z) << '\n';
    }

    return 0;
}