#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    int S = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        S += B[i];
    }

    // If the total power is not divisible by 3, return -1
    if (S % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    
    int target = S / 3;
    vector<vector<int>> dp(target + 1, vector<int>(target + 1, INT_MAX));
    dp[0][0] = 0;  // Base case: no people means zero swaps and zero power

    // Iterate over each person
    for (int i = 0; i < N; i++) {
        vector<vector<int>> new_dp = dp;  // Use new_dp to store updated states

        for (int x = 0; x <= target; x++) {
            for (int y = 0; y <= target; y++) {
                if (dp[x][y] == INT_MAX) continue;

                // Option 1: Keep person i in their original team
                new_dp[x][y] = min(new_dp[x][y], dp[x][y]);

                // Option 2: Move person to team 1
                if (x + B[i] <= target) {
                    new_dp[x + B[i]][y] = min(new_dp[x + B[i]][y], dp[x][y] + (A[i] != 1));
                }

                // Option 3: Move person to team 2
                if (y + B[i] <= target) {
                    new_dp[x][y + B[i]] = min(new_dp[x][y + B[i]], dp[x][y] + (A[i] != 2));
                }

                // Option 4: Move person to team 3
                int z = S - x - y;
                if (z - B[i] <= target && z >= B[i]) {
                    new_dp[x][y] = min(new_dp[x][y], dp[x][y] + (A[i] != 3));
                }
            }
        }

        dp = new_dp;  // Update dp with the new layer
    }

    int result = dp[target][target];
    cout << (result == INT_MAX ? -1 : result) << endl;
    return 0;
}
