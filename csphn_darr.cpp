#include<iostream>
#include<algorithm>
using namespace std;

long long a[(long long) 1e5 + 5], suff[(long long) 1e5 + 5];

signed main() {
    long long n, k;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    suff[n] = a[n];
    for(long long i = n - 1; i >= 1; i--) suff[i] = suff[i + 1] + a[i];
    sort(suff + 2, suff + n + 1, greater<>());
    long long ans = 0;
    for(long long i = 1; i <= k; i++) ans += suff[i];
    cout << ans;
}