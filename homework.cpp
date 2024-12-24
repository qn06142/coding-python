#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int n, m, k;
const int maxn = 500;
int t[maxn];
long long a[maxn], b[maxn];
long long dp[maxn][2][maxn][4][4]; 


long long solve(int idx, int person, int count, int prev_type1, int prev_type2) {
    
    if (idx == n) return 0;

    
    if (dp[idx][person][count][prev_type1][prev_type2] != -1)
        return dp[idx][person][count][prev_type1][prev_type2];

    long long res = INF;

    int cur_type = t[idx]; 

    
    if (count < k) { 
        long long time = (prev_type1 == cur_type) ? b[cur_type] : a[cur_type];
        res = min(res, time + solve(idx + 1, person, count + 1, cur_type, prev_type2));
    }

    
    long long time = (prev_type2 == cur_type) ? b[cur_type] : a[cur_type];
    res = min(res, time + solve(idx + 1, person, 1, prev_type1, cur_type));

    
    return dp[idx][person][count][prev_type1][prev_type2] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    
    memset(dp, -1, sizeof(dp));

    
    cout << min(solve(0, 0, 0, 0, 0), solve(0, 1, 0, 0, 0)) << '\n';

    return 0;
}