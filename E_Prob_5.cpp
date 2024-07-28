#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int N, M, D;
    std::cin >> N >> M >> D;

    std::vector<std::vector<int>> heights(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> heights[i][j];
            heights[i][j] += D * (i + 1);
        }
    }

    // Sort each row to facilitate comparisons
    for (int i = 0; i < N; ++i) {
        std::sort(heights[i].begin(), heights[i].end());
    }

    // Dynamic programming table
    std::vector<std::vector<long long>> dp(N, std::vector<long long>(M, 0));
    
    // Base case: First row can be any permutation
    for (int j = 0; j < M; ++j) {
        dp[0][j] = 1;
    }
    
    for (int i = 1; i < N; ++i) {
        std::vector<long long> prefixSum(M + 1, 0);
        
        // Calculate prefix sums for dp[i-1]
        for (int j = 0; j < M; ++j) {
            prefixSum[j + 1] = (prefixSum[j] + dp[i - 1][j]) % MOD;
        }
        
        // Calculate dp for current row using prefix sums
        int k = 0;
        for (int j = 0; j < M; ++j) {
            while (k < M && heights[i - 1][k] < heights[i][j]) {
                ++k;
            }
            dp[i][j] = prefixSum[k];
        }
    }
    
    // Sum up all ways to place students in the last row
    long long result = 0;
    for (int j = 0; j < M; ++j) {
        result = (result + dp[N - 1][j]) % MOD;
    }
    
    std::cout << result << std::endl;
    return 0;
}
