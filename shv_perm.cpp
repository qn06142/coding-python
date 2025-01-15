// C++ code to find number of permutation 
// with K inversions using Tabulation
#include <bits/stdc++.h>
using namespace std;

int countPermWithkInversions(int n, int k) {
  
    // Initialize a 2D table for dynamic programming
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: If k is 0, only one way to 
    // have 0 inversions: sorted order
    for (int l = 0; l <= n; l++) {
        dp[l][0] = 1;
    }

    // Fill the table using the tabulation method
    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= k; r++) {
            for (int i = 0; i <= min(r, l - 1); i++) {
              
                // Count permutations for the remaining 
                // elements and inversions
                dp[l][r] = (dp[l][r] + dp[l - 1][r - i]);
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << countPermWithkInversions(n, k);

    return 0;
}