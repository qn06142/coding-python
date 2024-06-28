#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

long long divs[MAXN]; // array to store the number of divisors for each number

// Fast exponentiation modulo m
long long powmod(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Sieve of Eratosthenes to find all prime numbers up to n
vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (int i = p * 2; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    return primes;
}

// Function to factorize all numbers from 1 to n
void factorize_up_to(int n, const vector<int>& primes) {
    for (int i = 2; i <= n; ++i) {
        int num = i;
        for (int prime : primes) {
            if (prime * prime > num) break;
            int cnt = 0;
            while (num % prime == 0) {
                cnt++;
                num /= prime;
            }
            divs[prime] = max(divs[prime], (long long)cnt);
        }
        if (num > 1) {
            divs[num] = max(divs[num], 1LL);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<int> primes = sieve(n);
    factorize_up_to(n, primes);

    long long ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (divs[i] > 0) {
            ans = ans * powmod(i, divs[i], MOD) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
