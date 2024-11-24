#include <bits/stdc++.h>
using namespace std;
#define int long long

struct machine {
    int a, p, b, q;
};

int n, X;
machine a[105];

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("arch=skylake")

static inline bool check(int x) {
    int cost = X;
    for (int i = 1; i <= n; i++) {
        int mincost = LLONG_MAX;

        for(int j = 0; j <= a[i].b; j++) {
            int cur = j * a[i].p;
            int needed = max(0LL, x - a[i].a * j);
            cur += (needed + a[i].b - 1) / a[i].b * a[i].q;
            mincost = min(mincost, cur);
        }

        for(int j = 0; j <= a[i].a; j++) {
            int cur = j * a[i].q;
            int needed = max(0LL, x - a[i].b * j);
            cur += (needed + a[i].a - 1) / a[i].a * a[i].p;
            mincost = min(mincost, cur);
        }

        cost -= mincost;
        if (cost < 0) return false; 
    }
    return cost >= 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> X;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].p >> a[i].b >> a[i].q;
    }

    int left = 1, right = 1e9, result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            result = mid;   
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    cout << result << "\n";
    return 0;
}