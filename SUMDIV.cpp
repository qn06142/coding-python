#include <iostream>
#include <cmath>
using namespace std;

const long long MOD = 1e9 + 7;

long long sumOfDivisorsInRange(long long L, long long R) {
    long long result = 0;
    for (long long d = 1; d * d <= R; ++d) {
        // Count multiples of `d` in the range [L, R]
        long long firstMultiple = (L + d - 1) / d * d;
        long long lastMultiple = (R / d) * d;

        if (firstMultiple <= lastMultiple) {
            // Number of multiples of `d` in the range [L, R]
            long long count = (lastMultiple - firstMultiple) / d + 1;
            result = (result + count * d) % MOD;
        }

        // Handle the counterpart divisor, R/d
        if (d != R / d) {
            long long dd = R / d;
            firstMultiple = (L + dd - 1) / dd * dd;
            lastMultiple = (R / dd) * dd;

            if (firstMultiple <= lastMultiple) {
                long long count = (lastMultiple - firstMultiple) / dd + 1;
                result = (result + count * dd) % MOD;
            }
        }
    }
    return result;
}

int main() {
    long long L, R;
    cin >> L >> R;
    cout << sumOfDivisorsInRange(L, R) << endl;
    return 0;
}
