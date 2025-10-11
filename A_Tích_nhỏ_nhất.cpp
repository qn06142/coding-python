#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
using ll = long long;
const ll MOD = 1000000007LL;

vector<int> sieve_primes(int limit) {
    vector<char> is_composite(limit + 1, false);
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (!is_composite[i]) {
            primes.push_back(i);
            if ((ll)i * i <= limit) {
                for (int j = i * i; j <= limit; j += i) is_composite[j] = true;
            }
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    const int LIMIT = 1e8; // sqrt(1e8) ~= 10000
    vector<int> primes = sieve_primes(LIMIT);
    
    while (T--) {
        int N;
        cin >> N;
        unordered_map<int,int> parity; 
        parity.reserve(1024);
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            int v = x;
            for (int p : primes) {
                if ((ll)p * p > v) break;
                if (v % p == 0) {
                    int cnt = 0;
                    while (v % p == 0) {
                        v /= p;
                        ++cnt;
                    }
                    if (cnt % 2 == 1) {
                        parity[p] ^= 1; // toggle parity for prime p
                    }
                }
            }
            if (v > 1) {
                // v is a prime > LIMIT (or remaining prime)
                parity[v] ^= 1;
            }
        }
        ll ans = 1;
        for (auto &kv : parity) {
            if (kv.second & 1) {
                ans = (ans * (ll)kv.first) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
