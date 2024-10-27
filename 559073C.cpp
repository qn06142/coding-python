#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

// Precompute factorials and inverses
vector<long long> fact(MAXN), inv_fact(MAXN);

// Function to perform modular exponentiation
long long mod_pow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = result * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return result;
}

// Precompute factorials and inverses modulo MOD
void precompute_factorials() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv_fact[MAXN-1] = mod_pow(fact[MAXN-1], MOD-2, MOD);  // Inverse using Fermat's Little Theorem
    for (int i = MAXN-2; i >= 1; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
    inv_fact[0] = 1; // 0! = 1 and its inverse is also 1
}

// Function to calculate nCk % MOD
long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n-k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Precompute factorials and inverse factorials
    precompute_factorials();
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        // Find maximum frequency
        int max_freq = 0;
        for (auto it : freq) {
            max_freq = max(max_freq, it.second);
        }
        
        // If any thought appears more than (n+1)/2 times, it's impossible to arrange them
        if (max_freq > (n + 1) / 2) {
            cout << 0 << '\n';
            continue;
        }
        
        // Calculate the number of valid permutations
        // The number of ways to arrange people is n! / (freq1! * freq2! * ...)
        long long result = fact[n];
        for (auto it : freq) {
            result = result * inv_fact[it.second] % MOD;
        }
        
        cout << result << '\n';
    }
    
    return 0;
}
