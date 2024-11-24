#include<bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

map<long long, int> primeFactorize(long long n) {
    map<long long, int> factors;
    for (long long i = 2; i * i <= n; ++i) {
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

long long countDivisorsFromFactors(const map<long long, int>& factors) {
    long long count = 1;
    for (const auto& factor : factors) {
        count = (count * (factor.second + 1)) % MOD;
    }
    return count;
}

int calcdivs(vector<int>& arr) {
    int n = arr.size();
    map<long long, int> totalFactors;
    for (long long num : arr) {
        map<long long, int> factors = primeFactorize(num);
        for (const auto& factor : factors) {
            totalFactors[factor.first] += factor.second;
        }
    }

    long long divisors = countDivisorsFromFactors(totalFactors);

    cout <<  divisors << endl;

    return 0;
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        a[x - 1] = y;
        calcdivs(a);
    }
    
}