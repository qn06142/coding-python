#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, int> primeFactorize(int n) {
    unordered_map<int, int> factors;
    for (int i = 2; i <= sqrt(n); i++) {
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

int calculateDistance(int a, int b) {
    unordered_map<int, int> factorsA = primeFactorize(a);
    unordered_map<int, int> factorsB = primeFactorize(b);

    int distance = 0;

    for (auto &factor : factorsA) {
        int prime = factor.first;
        int countA = factor.second;
        int countB = factorsB[prime];
        distance += abs(countA - countB);
        factorsB.erase(prime);
    }

    for (auto &factor : factorsB) {
        distance += factor.second;
    }

    return distance;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << calculateDistance(a, b) << endl;
    }
    return 0;
}