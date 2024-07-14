#include<bits/stdc++.h>

using namespace std;
int h[(int) 2e5 + 5];
int d[(int) 2e5 + 5];
int pref[(int) 2e5 + 5];
int n, q;
int dist(int i, int j) {
    if(i > j) swap(i, j);
    return pref[i] - pref[j - 1];
}
int f(int i, int j) {
    return 2 * (h[i] + h[j]) + dist(i, j);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i + n] = d[i];
        cin >> h[i];
        h[i + n] = h[i];
    }
    for(int i = 1; i <= n * 2; i++) {
        pref[i] = pref[i - 1] + d[i];
    }
    
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if(a > b) {
            for(int i = 1; i <= a; i++) { 
                for(int j = b; j <= n; j++) {
                    ans = max(ans, f(i, 1) + f(j, n));
                }
            }
        } else {
            for(int i = 1; i <= b; i++) { 
                for(int j = a; j <= n; j++) {
                    ans = max(ans, f(n, i) + f(j, 1));
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}