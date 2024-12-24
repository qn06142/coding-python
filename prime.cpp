#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 1;

int prime_index[MAX_N];
int min_prime[MAX_N];
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int num : v) {
            hash ^= hash * 31 + num;
        }
        return hash;
    }
};
void preprocess_sieve() {
    vector<int> primes;

    for (int i = 2; i < MAX_N; ++i) {
        if (min_prime[i] == 0) { 
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p * i >= MAX_N) break;
            if (min_prime[i] < p) break;
            min_prime[p * i] = p;
        }
    }

    for (size_t idx = 0; idx < primes.size(); ++idx) {
        prime_index[primes[idx]] = idx;
    }
}

int factorize(int num) {
    int ans = 1;
    while (num > 1) {
        int prime = min_prime[num];
        ans *= prime;
        while (num % prime == 0) { 
            num /= prime;
        }
    }

    return ans;
}
int p[(int) 1e6 + 5];
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess_sieve();
    for(int i = 1; i <= 1e6; i++) {
        p[i] = factorize(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        gp_hash_table<int, int> count_map;

        for (int num = a; num <= b; ++num) {
            count_map[p[num]]++;
        }

        long long total = 0;
        for  (auto [key, count] : count_map) {
            if (count >= 2) {
                total += static_cast<long long>(count) * (count - 1) / 2;
            }
        }

        cout << total << '\n';
    }

    return 0;
}