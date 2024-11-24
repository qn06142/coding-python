#include <bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e5 + 3;

int n;
long long k;
long long a[maxn], b[maxn];
pair<int, int> f[maxn];

bool check(long long xk) {
    long long cnt = 0;

    for(int i = 1; i <= n; i++) {
        f[i] = {1, 0};
        if(a[i] == 0) {
            if(xk >= 0) {
                cnt += n;    
                f[i] = {1, n};
            }
        }
        else {
            long long val = xk / a[i];

            if(a[i] < 0) {
                int u = lower_bound(b + 1, b + n + 1, val) - b;
                cnt += (n - u + 1);
                f[i] = {u, n};
            }
            else {
                int u = upper_bound(b + 1, b + n + 1, val) - b - 1;
                cnt += u;
                f[i] = {1, u};
            }
        }
    }
    return (cnt >= k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK ""
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    long long l = (long long) -1e18, r = (long long) 1e18, xk = 0;

    while(r - l >= 0) {
        long long mid = (l + r) / 2;

        if(check(mid)) {
            xk = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    check(xk);

    vector<long long> ans;
    bool flag = false;
    for(int i = 1; i <= n; i++) {
        for(int j = f[i].first; j <= f[i].second; j++) {
            if((long long) ans.size() <= k + 1e6)
            ans.emplace_back(a[i] * b[j]);
            else {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < min(k, (long long) ans.size()); i++) cout << ans[i] << " ";

    return 0;
}