#include<bits/stdc++.h>

using namespace std;
int a[(int) 1e5 + 5];
long long dp[(int) 1e5 + 5], pref[(int) 1e5 + 5], seq[(int) 4e5 + 5];
int n, k;
const long long L_LONG_MIN = -1e15;
void update(long long w, int u, int v, int node = 1, int l = 1, int r = n) {
    //from u to v
    if(l > v or r < u) {
        return;
    }
    //contains
    if(l >= u and r <= v) {
        seq[node] = max(seq[node], w);
    } else {
        int mid = (l + r) / 2;
        update(w, u, v, node * 2, l, mid);
        update(w, u, v, node * 2 + 1, mid + 1, r);
        seq[node] = max(seq[node * 2], seq[node * 2 + 1]);
    }
}
long long getmax(int u, int v, int node = 1, int l = 1, int r = n) {
    if(l > v or r < u) {
        return L_LONG_MIN;
    }
    if(l >= u and r <= v) {
        return seq[node];
    } else {
        int mid = (l + r) / 2;
        long long L, R;
        L = getmax(u, v, node * 2, l, mid);
        R = getmax(u, v, node * 2 + 1, mid + 1, r);
        return max(L, R);
    }
}
int main() {
    for(int i = 0; i <= 4e5 + 4; i++) {
        seq[i] = L_LONG_MIN;
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 1; i <= k; i++) {
        dp[i] = pref[i];
        update(dp[i - 2] - pref[i - 1], i, i);
    }
    for(int j = k + 1; j <= n; j++) {
        
        dp[j] = getmax(j - k + 1, j) + pref[j];
        //cout << max(1, j - k + 1) << ' ' << j  << ' ' << dp[j] << endl;
        update(dp[j - 2] - pref[j - 1], j, j);
        
    }
    long long ans = L_LONG_MIN;
    for(int i = 1; i <= n; i++) {
        //cout << dp[i] << ' ';
        ans = max(ans, dp[i]);
    }
    cout << ans;
}