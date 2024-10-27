#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000000;
vector<bool> is_prime(MAX_N + 1, true);

void sieve(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int count_prime_pairs(int n, int k) {
    sieve(n);
    int count = 0;
    for (int x = 2; x + k <= n; x++) {
        if (is_prime[x] && is_prime[x + k]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << count_prime_pairs(n, k) << endl;
    return 0;
}
