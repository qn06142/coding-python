#include<bits/stdc++.h>

using namespace std;
#define int long long
const int coins[] = {50000, 30000, 10000, 5000, 3000, 1000, 500, 300, 100, 50, 30, 10, 5, 3, 1};
signed solve() {    
    int a, b;
    cin >> a >> b;
    int ans = LONG_LONG_MAX;
    for(int i = 0; i <= 5e4; i++) {
        int t = b - a * i;
        if (t < 0) break;
        cout << t << endl;
        int count = i;
        for(int i = 0; i < 15; i++) {
            if(t >= coins[i]) cout << coins[i] << ' ';
            while(t >= coins[i]) {
                t -= coins[i];
                count++;
            }
        }
        cout << endl;
        ans = min(ans, count);
    }
    return ans;
}
signed main() {
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cout << solve() << '\n';
    }
}