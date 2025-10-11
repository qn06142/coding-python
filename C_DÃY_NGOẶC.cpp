#include <bits/stdc++.h>
using namespace std;

bool is_matching(char a, char b) {
    return (a=='(' && b==')')
        || (a=='[' && b==']')
        || (a=='{' && b=='}');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len = 2; len <= n; ++len){
        for(int i = 0; i + len - 1 < n; ++i){
            int j = i + len - 1;

            dp[i][j] = max(dp[i][j], dp[i+1][j]);

            dp[i][j] = max(dp[i][j], dp[i][j-1]);

            for(int k = i+1; k <= j; ++k){
                if(is_matching(s[i], s[k])){
                    int inside = (i+1 <= k-1 ? dp[i+1][k-1] : 0);
                    int after  = (k+1 <= j   ? dp[k+1][j]   : 0);
                    dp[i][j] = max(dp[i][j], inside + 2 + after);
                }
            }
        }
    }

    cout << s.size() - dp[0][n-1] << "\n";
}