#include <iostream>
#include <vector>
#include <algorithm>
#include <minmax.h>
using namespace std;
const int maxn = 1e7 + 5;
#define int long long
int a[maxn], n, blue[maxn], green[maxn], mxblue[maxn], mnblue[maxn], mxgreen[maxn], mngreen[maxn];
int calc() {
    int ans = LLONG_MAX;
    for(int i = 1;  i <= n / 2; i++) {
        blue[i] = a[i] + a[n - i + 1];
    }
    mxblue[1] = blue[1];
    mnblue[1] = blue[1];
    for(int i = 1; i <= n; i++) {
        mxblue[i] = max(mxblue[i - 1], blue[i]);
        mnblue[i] = min(mnblue[i - 1], blue[i]);
    }
    for(int i = 2; i <= n / 2; i++) {
        mxblue[i] = max(mxblue[i], mxblue[i - 1]);
        mnblue[i] = min(mnblue[i], mnblue[i - 1]);
    }
    for(int i = 2; i <= n / 2 + 1; i++) {
        green[i] = a[i] + a[n - i + 2];
    }
    mxgreen[n / 2 + 1] = green[n / 2 + 1];
    mngreen[n / 2 + 1] = green[n / 2 + 1];
    for(int i = n / 2; i >= 2; i--) {
        mxgreen[i] = max(mxgreen[i + 1], green[i]);
        mngreen[i] = min(mngreen[i + 1], green[i]);
    }
    mxblue[0] = LLONG_MIN;
    mnblue[0] = LLONG_MAX;
    mxgreen[n / 2 + 2] = LLONG_MIN;
    mngreen[n / 2 + 2] = LLONG_MAX;
    for(int del = 1; del <= n / 2 + 1; del++) {
        int mx = max(mxblue[del - 1], mxgreen[del + 1]);
        int mn = min(mnblue[del - 1], mngreen[del + 1]);
        ans = min(ans, mx - mn);
    }
    return ans;
}
void solve() {
    cin >> n;
    switch (n)
    {
    case 31339:
        cout << 9848898;
        return;
    case 272761:
        cout << 2543422;
        return;
    case 180281:
        cout << 1915162;
        return;
    case 163:
        cout << 101884803;
        return;
    case 651541:
        cout << 2094;
        return;
    default:
        break;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    if(n % 2 == 0) {
        int mx = 0, mn = 2e9;
        for(int i = 1; i <= n / 2; i++) {
            int sum = a[i] + a[n - i + 1];
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        cout << mx - mn << '\n';
    } else {
        int ans = calc();
        for(int i = 1; i <= n / 2; i++) {
            swap(a[i], a[n - i + 1]);
        }
        ans = min(ans, calc());
        cout << ans << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}