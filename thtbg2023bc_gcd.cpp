#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

unordered_map<int, int> primeFactors(int n) {
    unordered_map<int, int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

unordered_map<int, int> combinePrimeFactors(const vector<int>& arr) {
    unordered_map<int, int> combinedFactors;
    for (int num : arr) {
        unordered_map<int, int> factors = primeFactors(num);
        for (const auto& factor : factors) {
            combinedFactors[factor.first] += factor.second;
        }
    }
    return combinedFactors;
}

long long modularProductOfFactors(const unordered_map<int, int>& factors) {
    long long result = 1;
    for (const auto& factor : factors) {
        for (int i = 0; i < factor.second; i++) {
            result = (result * factor.first) % MOD;
        }
    }
    return result;
}

long long computeGCD(long long a, long long b) {
    if (b == 0)
        return a;
    return computeGCD(b, a % b);
}

long long f(const vector<int>& a, const vector<int>& b) {
    unordered_map<int, int> factorsA = combinePrimeFactors(a);
    unordered_map<int, int> factorsB = combinePrimeFactors(b);

    unordered_map<int, int> commonFactors;
    for (const auto& factor : factorsA) {
        if (factorsB.count(factor.first)) {
            commonFactors[factor.first] = min(factor.second, factorsB[factor.first]);
        }
    }

    return modularProductOfFactors(commonFactors);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << f(a, b) << endl;

    return 0;
}
