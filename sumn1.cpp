#include <iostream>
using namespace std;

const int MOD = 1000000;

long long calc(long long n) {
    long long sum = 0;
    for (long long i = 1; i <= n; ) {
        long long v = n / i; 
        long long next_i = n / v + 1; 
        sum = (sum + v * (next_i - i)) % MOD;
        i = next_i;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << calc(n) << "\n";
    }
    return 0;
}