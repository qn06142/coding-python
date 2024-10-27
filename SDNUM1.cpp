#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll mod = 1000000007;
ll dp[1005][3005][2];
ll powers[1005];
int n, k;
void init() {
    ll st = 1;
    for (int i = 0; i <= n; i++) {
        powers[i] = st;
        st *= 10;
        st %= mod;
    }
}
ll calc(int id, int rem, int nonz) {
    // Base case
    if (rem == 0 && nonz) {
        if (id != n)
            return (powers[n - id - 1] * 9) % mod;
        else
            return 1;
    }
    if (id == n)
        return 0;
    if (dp[id][rem][nonz] != -1)
        return dp[id][rem][nonz];
    ll count = 0;
    for (int i = 0; i < 10; i++) {
        count = (count + (calc(id + 1, (rem + (i * powers[id]) % k) % k, nonz || (i > 0)))) % mod;
    }
    return dp[id][rem][nonz] = count;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    init();
    memset(dp, -1, sizeof(dp));
    cout << calc(0, 0, 0);
    return 0;
}