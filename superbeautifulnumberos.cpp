#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
bool isprime[(int)1e6 + 5];

void sieve() {
    for (int i = 0; i <= (int)1e6 + 5; i++) {
        isprime[i] = true;
    }
    for (int p = 2; p <= 1e3; p++) {
        if (isprime[p]) {
            for (int i = p * p; i <= 1e6; i += p) {
                isprime[i] = false;
            }
        }
    }
    for (int p = 2; p <= 1e6; p++) {
        if (isprime[p]) {
            primes.push_back((long long) p * p * p);
            //cout << p << " ";
        }
    }
    //cout << endl;
}

int main() {
    long long n;
    cin >> n;
    int count = 0;
    sieve();
    for (int i = 0; i <= (int)cbrt(n); i++) {
        if ((long long)primes[i] > n) break;
        int tmp = upper_bound(primes.begin(), primes.end(), n / ((long long)cbrt(primes[i]))) - primes.begin();
        if (tmp >= i + 1) {
            //cout << tmp << " " << primes[i] << endl; 
            count += tmp - i - 1;
        }
    }
    cout << count << endl;
    return 0;
}
