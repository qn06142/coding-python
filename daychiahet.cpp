#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 5e6 + 5;
int n, a[maxn], sufmx[maxn], prefmx[maxn], pref[maxn], k;
int mp1[(int) 1e6 + 5], mp2[(int) 1e6 + 5];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    memset(mp1, -1, sizeof(mp1));
    memset(mp2, -1, sizeof(mp2));
    mp1[pref[0] % k] = 0;
    for(int j = 1; j <= n; j++) {
        int il = LLONG_MAX;
        if(mp1[pref[j] % k] >= 0) {
            il = mp1[pref[j] % k];
        }
        int len = j - il;
        if(mp1[pref[j] % k] == -1) mp1[pref[j] % k] = j;
        prefmx[j] = max(prefmx[j - 1], len);
    }
    mp2[pref[n] % k] = n;
    for(int i = n; i >= 1; i--) {
        int j = LLONG_MIN;
        if(mp2[pref[i - 1] % k] >= -1) {
            j = mp2[pref[i - 1] % k];
        }
        int len = j - i + 1;
        if(mp2[pref[i] % k] == -1) mp2[pref[i] % k] = i;
        sufmx[i] = max(sufmx[i + 1], len);
    }
    int ans = 0;
    for(int j = 1; j <= n; j++) {
        if(prefmx[j] >= 1 and sufmx[j + 1] >= 1) {
            ans = max(ans, prefmx[j] + sufmx[j + 1]);
        }
    }
    cout << ans;
}