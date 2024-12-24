#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int, int> a[(int)2e5 + 5];

bool check(int d, int n, int k) {
    long long t = a[1].second, r = a[1].second;
    for(int i = 2; i <= n; ++i){
        if(a[i].first - a[i - 1].first > d) t = 0;
        t += a[i].second;
        r = max(r, t);
    }
    return r > k;
}

signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    sort(a + 1, a + 1 + n); 

    int low = 0, high = 1e9, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid, n, k)) {
            ans = mid; 
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }

    cout << ans;
    return 0;
}