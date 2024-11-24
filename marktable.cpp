#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
    cin >> n;

        long long ans = 0;

        for (long long i = 1; i * i <= n; i += 2) {
            ans += (n / i) - (n / (i + 1));
        }

        for (long long i = 1; i * i < n; ++i) {
            if (n/i % 2 != 0) {
                if (n/i == (long long) sqrt(n)) {
                    continue;
                }
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}