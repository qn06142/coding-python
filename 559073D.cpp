#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353

using namespace std;

// Function to compute factorial % MOD
long long factorial(int x) {
    long long res = 1;
    for (int i = 2; i <= x; i++) {
        res = res * i % MOD;
    }
    return res;
}

// Function to compute modular exponentiation (a^b % MOD)
long long mod_pow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

// Function to compute modular inverse using Fermat's Little Theorem
long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}

// Function to compute nCr % MOD
long long nCr(int n, int r, vector<long long>& fact, vector<long long>& inv_fact) {
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    // Step 1: Sort the array
    sort(a.begin(), a.end());

    // Step 2: Calculate the sum of absolute differences between the two groups
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost = (cost + a[n + i] - a[i]) % MOD;
    }

    // Step 3: Precompute factorials and modular inverses
    vector<long long> fact(2 * n + 1), inv_fact(2 * n + 1);
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[2 * n] = mod_inv(fact[2 * n], MOD);
    for (int i = 2 * n - 1; i >= 1; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    // Step 4: Compute the number of ways to choose n elements from 2n
    long long ways = nCr(2 * n, n, fact, inv_fact);

    // Step 5: Calculate the final result
    long long result = cost * ways % MOD;
    cout << result << endl;

    return 0;
}
