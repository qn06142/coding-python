#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }

        long long sum = 0;

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {

            long long ddd = max(0LL, a[i] - b[(i - 1 + n) % n]);
            sum += ddd;

            ans = min(ans, a[i] - ddd);
        }

        cout << sum + ans << "\n";
    }

    return 0;
}