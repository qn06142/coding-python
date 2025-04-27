#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define int long long
    string X;
    cin >> X;
    int n = X.size();

    vector<vector<int>> nxt(n+1, vector<int>(10, -1));
    for (int d = 0; d < 10; d++){
        nxt[n][d] = -1;
    }
    for (int i = n - 1; i >= 0; i--){
        for (int d = 0; d < 10; d++){
            nxt[i][d] = nxt[i+1][d];
        }
        int cur = X[i] - '0';
        nxt[i][cur] = i;
    }

    int INF = n + 2;
    vector<int> dp(n+1, INF);
    dp[n] = 1; 

    for (int i = n - 1; i >= 0; i--){
        dp[i] = INF;
        for (int d = 0; d < 10; d++){
            int candidate;
            if(nxt[i][d] == -1){
                candidate = 1;
            } else {
                candidate = 1 + dp[nxt[i][d] + 1];
            }
            dp[i] = min(dp[i], candidate);
        }
    }

    string ans = "";
    int i = 0;
    int len = dp[0];
    for (int pos = 0; pos < len; pos++){

        int startDigit = ans.empty() ? 1 : 0;
        for (int d = startDigit; d < 10; d++){
            int candlen;
            if(nxt[i][d] == -1){
                candlen = 1;
            } else {
                candlen = 1 + dp[nxt[i][d] + 1];
            }
            if(candlen == dp[i]){
                ans.push_back('0' + d);
                if(nxt[i][d] == -1)
                    i = n;  
                else
                    i = nxt[i][d] + 1;
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
