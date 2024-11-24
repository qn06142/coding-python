#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6; 
vector<int> primes;
vector<bool> isgood;
vector<int> pref;

void sieve(int n) {
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isprime[i]) {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) primes.push_back(i);
    }
}

bool checkBeautiful(int n) {
    for (int p : primes) {
        if (p * p > n) break;
        int count = 0;
        while (n % p == 0) {
            n /= p;
            count++;
        }
        if (count > 1) return false; 
    }
    return n == 1 || n > 1; 
}

void precompute() {
    isgood.resize(MAXN + 1, true);
    pref.resize(MAXN + 1, 0);
    for (int i = 1; i <= MAXN; ++i) {
        isgood[i] = checkBeautiful(i);
        pref[i] = pref[i - 1] + isgood[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve(1000); 
    precompute();

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
    }

    return 0;
}