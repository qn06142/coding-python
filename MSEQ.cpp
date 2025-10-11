#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("MSEQ.INP");
    ofstream fout("MSEQ.OUT");

    int n;
    fin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) fin >> a[i];

    const int NEG = -1000000000;
    vector<int> cnt(n+2, 0);
    vector<int> dp(n+2, NEG);
    vector<int> best(n+2, NEG);

    dp[1] = 0;
    best[1] = 0; 
    int max_ = best[1];

    for (int r = 1; r <= n; ++r) {
        int s = r - a[r] + 1; 
        if (1 <= s && s <= n) {
            cnt[s] += 1;
            if (best[s] > NEG/2) { 
                best[s] += 1;
                if (best[s] > max_) max_ = best[s];
            }
        }
        dp[r+1] = max_;
        if (dp[r+1] > NEG/2) {

            best[r+1] = dp[r+1] + cnt[r+1];
            if (best[r+1] > max_) max_ = best[r+1];
        }
    }

    int tot = dp[n+1];
    if (tot < 0) tot = 0; 
    int ans = n - tot;
    fout << ans << '\n';
}