#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;

map<long long, int> factorize(long long x) {
    map<long long, int> factors;
    for (long long i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        factors[x] = 1;
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<long long, int> combined_factors;
    for (int i = 0; i < n; ++i) {
        map<long long, int> factors = factorize(a[i]);
        for (const auto& [prime, exp] : factors) {
            combined_factors[prime] = max(combined_factors[prime], exp);
        }
    }
    long long c = 1;
    for (const auto& [prime, exp] : combined_factors) {
        cout << prime << "^" << exp << " ";
    }
    cout << "\n";

    return 0;
}