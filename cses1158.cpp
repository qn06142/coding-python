#include<bits/stdc++.h>
using namespace std;
 
int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(2, vector<int>(W+1, 0));
    int flag = 0;
 
    for (int i = 1; i <= n; i++) {
        flag = 1 - flag;
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[flag][w] = max(dp[1-flag][w], val[i-1] + dp[1-flag][w-wt[i-1]]);
            } else {
                dp[flag][w] = dp[1-flag][w];
            }
        }
    }
 
    return dp[flag][W];
}
 
int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), profit(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        cin >> profit[i];
    }
    cout << knapSack(w, weight, profit, n) << endl;
    return 0;
}