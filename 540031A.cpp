#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[2 * MAXN], pref[2 * MAXN];

bool check(int x, int n) {
    for (int i = 1; i <= 2 * n - x; i++) {
        if (pref[2 * n] - (pref[i + x] - pref[i - 1]) == 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n * 2; i++) {
            cin >> a[i];
        }
        
        // Reset prefix array
        fill(pref, pref + n + 1, 0);
        
        for (int i = 1; i <= n * 2; i++) {
            pref[i] = pref[i - 1] + (a[i] == 1 ? -1 : 1);
        }
        map<int, int> prefmap;
        int ans = INT_MAX;
        for(int i = 1; i <= n + 1; i++) {
            prefmap[pref[i - 1]] = i;
        }
        for(int i = n; i <= 2 * n; i++) {
            if(prefmap[pref[i]  - pref[2 * n]]) {
                ans = min(ans, i - prefmap[pref[i] - pref[2 * n]] + 1);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
