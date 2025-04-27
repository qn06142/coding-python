#include <iostream>
#include <vector>
using namespace std;

const int MOD = 123456789;

int main(){
    int n;
    long long c;
    cin >> n >> c;
    int cap1 = n * (n - 1) / 2;

    if(c > cap1){
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp(n+1, vector<int>(cap1+1, 0));
    dp[0][0] = 1; 

    for(int i = 1; i <= n; i++){

        int cap = i * (i - 1) / 2;

        vector<int> pref(cap + 1, 0);
        pref[0] = dp[i-1][0];
        for(int j = 1; j <= cap; j++){
            pref[j] = (pref[j-1] + dp[i-1][j]) % MOD;
        }

        for(int j = 0; j <= cap; j++){
            if(j < i)
                dp[i][j] = pref[j];
            else {

                dp[i][j] = (pref[j] - pref[j - i] + MOD) % MOD;
            }
        }
    }

    cout << dp[n][c] % MOD << endl;
    return 0;
}