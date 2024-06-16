#include<bits/stdc++.h>

using namespace std;
int dp[(int) 3e4 + 5], a[(int) 3e4 + 5], bit[(int) 3e4 + 5];
int n;
void update(int u, int v) {
    while(u <= n) {
        bit[u] = max(bit[u], v);
        u += (u & (-u));
    }
}
int query(int u) {
    int ans = 0;
    while(u) {
        ans = max(ans, bit[u]);
        u -= (u & (-u));
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> compress(n);
    for(int i = 0; i < n; i++) {
        compress[i] = a[i + 1];
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin() + 1;
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        dp[i] = query(a[i] - 1) + 1;/*
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j] and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }*/
        update(a[i], dp[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}