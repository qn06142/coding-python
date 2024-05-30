#include<iostream>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;

unordered_map<long long, long long> factors;
void primeFactorization(int n) {
    while (n % 2 == 0) {
        factors[2]++;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            factors[i]++;
            n = n/i;
        }
    }

    if (n > 2)
        factors[n]++;
}
long long pow(long long base, long long exp, int mod = (int) 1e9 + 7) {
    long long ans = 1;
    for(int i = 1; i <= exp; i++) ans = (ans * base) % mod;
    return ans;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    primeFactorization(a);
    primeFactorization(b);
    primeFactorization(c);
    long long ans = LONG_LONG_MAX;
    for(auto i:factors) {
        ans = min(ans, i.second);
        cout << i.first << ':' << i.second << endl;;
    }
    cout << ans;
}