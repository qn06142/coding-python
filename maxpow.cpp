#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define int long long
vector<pair<int, int>> prime_factorize(int m) {
    vector<pair<int, int>> factors;
    for (int i = 2; i <= sqrtl(m); i++) {
        if (m % i == 0) {
            int count = 0;
            while (m % i == 0) {
                m /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (m > 1) {
        factors.push_back({m, 1});
    }
    return factors;
}

int power_in_factorial(int n, int p) {
    int power = 0;
    for (int i = p; i <= n; i *= p) {
        power += n / i;
    }
    return power;
}

int find_largest_k(int n, int m) {
    vector<pair<int, int>> factors = prime_factorize(m);
    int min_k = 1e12;
    for (auto& factor : factors) {
        int prime = factor.first;
        int exponent = factor.second;
        int power_in_fact = power_in_factorial(n, prime);
        int k_for_this_prime = power_in_fact / exponent;
        min_k = min(min_k, k_for_this_prime);
    }
    if(min_k == 0) min_k = -1;
    return min_k;
}

signed main() {
    int n, m;
    cin >> n >> m;

    cout << find_largest_k(n, m) << endl;

    return 0;
}
