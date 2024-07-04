#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[(int) 1e5 + 5], l[(int) 2e5 + 5], r[(int) 2e5 + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; i++) {
        l[i] = max(a[i - 1], a[i + 1]) + 1;
        r[i] = a[i];
        if(l[i] > r[i]) {continue;}
        v.push_back({l[i], 1});
        v.push_back({r[i] + 1, -1});
    }
    sort(v.begin(), v.end());
    int ans = 0, sum = 0;
    for(auto x : v) {
        sum += x.second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}