#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(int max_val) {
    vector<bool> is_prime(max_val + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_val; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_val; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int MAX_VAL = 1e6;
    vector<bool> is_prime = sieve(MAX_VAL);

    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        long long result = 0;

        for (int i = 0; i < e; ++i) {
            vector<int> primes;
            for (int j = i; j < n; j += e) {
                if (is_prime[A[j]]) {
                    primes.push_back(j);
                }
            }

            for (int idx : primes) {

                int left = 0, right = 0;
                while (idx - (left + 1) * e >= 0 && A[idx - (left + 1) * e] == 1) {
                    ++left;
                }
                while (idx + (right + 1) * e < n && A[idx + (right + 1) * e] == 1) {
                    ++right;
                }

                result += (long long)(left + 1) * (right + 1) - 1;
            }
        }

        cout << result << '\n';
    }

    return 0;
}