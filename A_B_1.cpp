#include <bits/stdc++.h>

using namespace std;

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(m);        
    vector<int> op(n + 1);              
    vector<vector<int>> del(n + 1);     

    for (auto &e : a) {
        cin >> e.first >> e.second;
        op[e.first]++;                  
        del[e.second].emplace_back(e.first);  
    }

    multiset<int> cur;                  
    vector<int> dp(n + 1);              

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];              

        for (int j = 0; j < op[i]; ++j) {
            cur.insert(i);
        }

        if (!cur.empty()) {
            dp[i] = max(dp[i], dp[*cur.begin() - 1] + int(cur.size()));
        }

        for (int e : del[i]) {
            cur.erase(cur.find(e));
        }
    }

    cout << dp[n];
}

bool multi = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi) {
        cin >> t;                        
    }

    for (int i = 1; i <= t; ++i) {
        solve(i);                        
        cout << "\n";                    
    }

    return 0;
}