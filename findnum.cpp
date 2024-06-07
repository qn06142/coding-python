#include<bits/stdc++.h>

using namespace std;
int a[(int) 2e3 + 5];
int main() {
    int q;
    cin >> q;
    while(q--) {
        int n, k, m, r;
        cin >> n >> k >> m >> r;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = INT_MAX;
        for(int t = 1; t <= n; t++) {
            vector<int> adup(n + 5);
            for(int i = 1; i <= n; i++) {
                adup[i] = a[i] + (m - r * (n - 1)) * t;
            }
            int minelem = *min_element(adup.begin() + 1, adup.end() - 4);
            for(int i = 1; i <= n; i++) {
                int minelem1 = minelem;
                int operations = ceil(adup[i] / m);
                minelem1 -= r * operations; 
                if(minelem1 >= k) {
                    ans = min(ans, t + operations);
                }
            }
        }
        cout << ans << "\n";
    }
}