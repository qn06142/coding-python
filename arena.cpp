#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../headers/debug.h"
#else
#define debug(...) 42
#endif

int n;
string s;
int dp[(int) 2e5 + 3][4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> s;
    n = (int) s.size();
    s = " " + s;

    memset(dp, -0x3f, sizeof dp);

    if(s[1] == 'D') dp[1][0] = 1;
    else if(s[1] == 'L') dp[1][0] = 0;
    else if(s[1] == 'W') dp[1][1] = 2;

    int prefmax[4];
    for(int i = 1; i < 4; i++) prefmax[i] = -1e9; 
    for(int x = 0; x <= 3; x++) {
        prefmax[x] = max(prefmax[x], dp[1][x]);
    }
    for(int i = 2; i <= n; i++) {
        if(s[i] != 'W') {
            for(int x = 0; x <= 3; x++) {
                dp[i][0] = max(dp[i][0], prefmax[x] + (s[i] == 'D'));
            }
        }
        else {
            for(int x = 1; x <= 3; x++) {
                if(x <= 2) {
                    dp[i][x] = max(dp[i][x], prefmax[x - 1] + 2);
                }
                else {
                    dp[i][x] = max(dp[i][x], max(prefmax[x - 1], prefmax[3]) + 3);
                }
            }
        }
        for(int x = 0; x <= 3; x++) {
            prefmax[x] = max(prefmax[x], dp[i][x]);
        }
    }/*
    for(int i = 1; i <= n; i++) {
            for(int x = 0; x <= 3; x++){
                cout << dp[i][x] << ' ';
            }
            cout << endl;
    }*/
    int res = 0;
    for(int i = 1; i <= n; i++) for(int x = 0; x <= 3; x++) res = max(res, dp[i][x]);

    cout << res;

    return 0;
}
