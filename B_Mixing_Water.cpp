#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int h, c, t;
        cin >> h >> c >> t;

        if (h + c - 2 * t >= 0) {
            cout << 2 << '\n';
        } else {
            int a = h - t;
            int b = 2 * t - c - h;
            int k = 2 * (a / b) + 1;

            long long val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
            long long val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));

            cout << (val1 * (k + 2) <= val2 * k ? k : k + 2) << '\n';
        }
    }

    return 0;
}
