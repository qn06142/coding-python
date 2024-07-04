#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
int minsuma[(int) 1e6 + 5];
int minsumb[(int) 1e6 + 5];
signed main() {
    
    int n, m, x;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    vector<int> prefa(n + 1);
    vector<int> prefb(m + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefa[i] = prefa[i - 1] + a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        prefb[i] = prefb[i - 1] + b[i];
    }

    // Prepare for b: min sum of length

    for (int lenb = 1; lenb <= m; lenb++) {
        minsumb[lenb] = INT_MAX;
        for (int i = 0; i <= m - lenb; i++) {
            minsumb[lenb] = min(minsumb[lenb], prefb[i + lenb] - prefb[i]);
        }
    }

    // Prepare for a: min sum of length

    for (int lena = 1; lena <= n; lena++) {
        minsuma[lena] = INT_MAX;
        for (int i = 0; i <= n - lena; i++) {
            minsuma[lena] = min(minsuma[lena], prefa[i + lena] - prefa[i]);
        }
    }

    int ans = 0;
    // Find the maximum area
    for (int lena = 1; lena <= n; lena++) {
        for (int lenb = 1; lenb <= m; lenb++) {
            if (minsuma[lena] * minsumb[lenb] <= x) {
                ans = max(ans, lena * lenb);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
