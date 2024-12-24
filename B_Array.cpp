#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_x = (1LL << k); // 2^K
    vector<int> f(max_x, n + 1); // Initialize with a large value (n+1 is out of bounds)

    // Precompute the smallest index for each possible x
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < max_x; ++mask) {
            int value = mask & a[i];
            if (value != a[i]) {
                f[mask] = min(f[mask], i + 1); // Store 1-based index
            }
        }
    }

    // Calculate the sum of F(x)
    long long result = 0;
    for (int x = 0; x < max_x; ++x) {
        if (f[x] <= n) { // Valid index
            result = (result + f[x]) % MOD;
        }
    }

    cout << result << "\n";
    return 0;
}
