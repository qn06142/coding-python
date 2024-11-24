#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 20;
int a[MAXN][MAXN];
int dp[1 << MAXN];
bool valid[1 << MAXN];
int subset[MAXN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            dp[(1 << i) | (1 << j)] = a[i][j];
        }
    }
    int limit = 1 << N;
    for (int mask = 0; mask < limit; mask++) {
        for (int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(((mask >> i) & (mask >> j) & 1)) {
                    subset[mask] += a[i][j];
                }
            }
        }
    }
    
    for (int m=0; m<(1<<N); ++m)
        for (int s=m; s; s=(s-1)&m) {
            dp[m] = max({dp[m], dp[m - s] + subset[s]});
        }

    cout << dp[(1 << N) - 1];
    return 0;
}
