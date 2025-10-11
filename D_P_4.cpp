#include <bits/stdc++.h>
using namespace std;
const long long NEG = (long long)-4e18;

int N, W;
vector<vector<int>> children;
vector<int> parent_, wt, val;

vector<long long> dfs(int u){
    vector<long long> dp(W+1, NEG);

    if (wt[u] <= W) dp[wt[u]] = val[u];

    vector<pair<int,long long>> nonneg;
    for (int v : children[u]) {
        vector<long long> child = dfs(v);
        nonneg.clear();
        for (int w = 0; w <= W; ++w) if (child[w] != NEG) nonneg.push_back({w, child[w]});
        for (int curw = W; curw >= 0; --curw) {
            if (dp[curw] == NEG) continue;
            for (auto [cw, valc] : nonneg) {
                if (curw + cw > W) break;
                dp[curw + cw] = max(dp[curw + cw], dp[curw] + valc);
            }
        }
    }

    return dp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> W;
    parent_.assign(N+1, 0);
    children.assign(N+1, {});
    wt.assign(N+1, 0);
    val.assign(N+1, 0);

    for (int i = 1; i <= N; ++i) cin >> parent_[i];
    for (int i = 1; i <= N; ++i) cin >> wt[i];
    for (int i = 1; i <= N; ++i) cin >> val[i];

    for (int i = 1; i <= N; ++i){
        if (parent_[i] != 0) children[parent_[i]].push_back(i);
    }

    vector<int> roots;
    for (int i = 1; i <= N; ++i) if (parent_[i] == 0) roots.push_back(i);
    children[0] = roots;
    wt[0] = 0; val[0] = 0;

    vector<long long> dp0 = dfs(0);
    long long ans = 0;
    for (int w = 0; w <= W; ++w) if (dp0[w] != NEG) ans = max(ans, dp0[w]);
    cout << ans << "\n";
}