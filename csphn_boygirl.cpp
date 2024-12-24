#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    if (abs(n - m) > 1) {
        cout << 0 << endl;
    } else {
        long long fact_n = factorial(n);
        long long fact_m = factorial(m);
        if (n == m) {
            cout << (2 * fact_n % MOD * fact_m % MOD) << endl;
        } else {
            cout << (fact_n * fact_m % MOD) << endl;
        }
    }
    
    return 0;
}
