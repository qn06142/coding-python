#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 4005;
int dp[MAXN][MAXN]; 
vector<pair<int, int>> chords; 
vector<int> startAt[MAXN], endAt[MAXN]; 

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v); 
        chords.push_back({u, v});
        startAt[u].push_back(v); 
        endAt[v].push_back(u);   
    }

    for (int len = 2; len <= 2*n; ++len) { 
        for (int l = 1; l <= 2*n-len+1; ++l) {
            int r = l + len - 1; 

            dp[l][r] = dp[l+1][r]; 

            for (int v : startAt[l]) {
                if (v <= r) {

                    dp[l][r] = max(dp[l][r], dp[l+1][v-1] + dp[v+1][r] + 1);
                }
            }
        }
    }

    cout << dp[1][2*n] << endl;

    return 0;
}