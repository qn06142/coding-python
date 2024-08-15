#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int INF = 1LL << 60;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int ans = 0;
    int a[k];
    for (int i = 0; i < k; i++) 
        cin >> a[i];

    for (int i = 1; i < (1 << k); i++) {
        int x = (__builtin_popcount(i) & 1) ? 1 : -1;
        int y = n;
        int z = 1;
        
        for (int j = 0; j < k; j++) {
            if (i >> j & 1) {
                if (z >= n / a[j] + 1) {
                    z = INF;
                    break;
                }
                z *= a[j];
            }
        }
        y /= z;
        ans += x * y;
    }

    cout << ans << endl;
}
