#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e6 + 7;
long long minprime[MAXN];
long long cnt[MAXN];
long long n, m;

// sieve of Eratosthenes to find the smallest prime factor of each number
void sieve(long long n) {
    fill(minprime, minprime + n + 1, 0); // initialize minprime to 0
    minprime[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (minprime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (minprime[j] == 0) {
                    minprime[j] = i;
                }
            }
            minprime[i] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (minprime[i] == 0) {
            minprime[i] = i;
        }
        if (i % 2 == 0) {
            minprime[i] = 2;
        }
    }
}

// compress a number by its prime factors
long long F(long long z) {
    long long res = 1;
    if (z == 1) {
        return 1;
    }
    while (z > 1) {
        long long mu = 0;
        long long k = minprime[z];
        while (z % k == 0 && z > 1) {
            z /= k;
            mu++;
        }
        // if the power is odd, multiply the result by the prime factor
        if (mu % 2 == 1) {
            res *= k;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    sieve(1e6);
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        long long z = F(i);
        cnt[z]++;
        // for each number i from 1 to n, update count array with the compressed number
    }
    for (int i = 1; i <= n; i++) {
        res *= (cnt[i] + 1) % m;
        res %= m;
    }
    cout << res;
    return 0;
}