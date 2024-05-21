#include<iostream>
#include<map>
using namespace std;


int dp[(int) 1e3 + 5][(int) 1e3 + 5];
map<int, map<int, bool>> poses;

int main() {
    int m, n, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        poses[a][b] = 1;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(poses[i - 1][j] == 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= (int) (1e9 + 7);
            }
            if(poses[i][j - 1] == 0) {
                dp[i][j] += dp[i][j -1];
                dp[i][j] %= (int) (1e9 + 7);
            }
            dp[i][j] %= (int) (1e9 + 7);
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << dp[n][m];
}