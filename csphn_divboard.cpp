#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#pragma GCC optimize("Ofast")
int a[1005][1005];
int pref[1006][1006];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }

    
    auto getSum = [&](int x1, int y1, int x2, int y2) -> int {
        return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
    };

    int ans = INT_MAX;

    
    for (int i = 1; i < n; i++) { 
        for (int j = 1; j < m; j++) {
            for(int k = 1; k < m; k++) {
                int par1 = getSum(0, 0, i - 1, j - 1);         
                int par2 = getSum(0, j, i - 1, m - 1);         
                int par3 = getSum(i, 0, n - 1, k - 1);         
                int par4 = getSum(i, k, n - 1, m - 1);         
                ans = min(ans, max(max(par1, par2),max(par3, par4)) - min(min(par1, par2), min(par3, par4)));
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
