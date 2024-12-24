#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, layout;
int dp[(1 << 20)];
vector<int> assoc[26];
int adj[26][26];
int main() {
    cin >> n >> m >> s;

    layout = "";
    for (int i = 0; i < m; i++) {
        layout += char('a' + i);
    }

    for (int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            adj[s[i - 1] - 'a'][s[i] - 'a']++;
            adj[s[i] - 'a'][s[i - 1] - 'a']++;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(adj[i][j]) {
                assoc[i].push_back(j);
            }
        }
    }
    fill(dp, dp + (1 << m), INT_MAX);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) continue;

            int tot = 0;
            int cnt = __builtin_popcount(mask);
            for (int j : assoc[layout[i] - 'a']) {
                if(mask >> j & 1)
                tot += cnt * adj[i][j];
                else
                tot -= cnt * adj[i][j];
            }

            int newmask = mask | (1 << i);
            dp[newmask] = min(dp[newmask], dp[mask] + tot);
        }
    }

    cout << dp[(1 << m) - 1] << endl;

    return 0;
}
