#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }

        int max_mask = (1 << n);
        vector<vector<int>> dp(max_mask, vector<int>(n, 0)); 
        vector<vector<int>> count(max_mask, vector<int>(n, 0)); 

        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = height[i] + 2; 
            count[1 << i][i] = 1; 
        }

        for (int mask = 0; mask < max_mask; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue; 

                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue; 
                    int new_mask = mask | (1 << j);
                    int contribution = abs(height[i] - height[j]) + 2;
                    int new_perimeter = dp[mask][i] + contribution;

                    if (new_perimeter > dp[new_mask][j]) {
                        dp[new_mask][j] = new_perimeter;
                        count[new_mask][j] = count[mask][i];
                    } else if (new_perimeter == dp[new_mask][j]) {
                        count[new_mask][j] += count[mask][i];
                    }
                }
            }
        }

        int max_perimeter = 0, ways = 0;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] + height[i] > max_perimeter) {
                max_perimeter = dp[(1 << n) - 1][i] + height[i];
                ways = count[(1 << n) - 1][i];
            } else if (dp[(1 << n) - 1][i] + height[i] == max_perimeter) {
                ways += count[(1 << n) - 1][i];
            }
        }

        cout << max_perimeter << " " << ways << "\n";
    }

    return 0;
}
