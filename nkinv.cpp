#include<bits/stdc++.h>

using namespace std;
#define int long long
int dp[(int) 6e4 + 5], a[(int) 6e4 + 5], bit[(int) 6e4 + 5];
int n;
void update(int u, int v) {
    while(u) {
        bit[u] += v;
        u -= (u & (-u));
    }
}
int query(int u) {
    int ans = 0;
    while(u <= 6e4 + 5) {
        ans += bit[u];
        u += (u & (-u));
    }
    return ans;
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long count = 0;
    update(a[1], 1);
    for(int i = 2; i <= n; i++) {
        count += query(a[i] + 1);
        update(a[i], 1);
    }
    cout << count;
}