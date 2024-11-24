#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;

int countBeautifulSubmatrices(const vector<vector<int>>& matrix, int m, int n) {
    // Step 1: Compute the prefix sum matrix
    vector<vector<ll>> prefix_sum(m + 1, vector<ll>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix_sum[i][j] = matrix[i-1][j-1] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }

    ll beautiful_count = 0;

    // Step 2: Iterate over all pairs of rows
    for (int r1 = 1; r1 <= m; ++r1) {
        for (int r2 = r1; r2 <= m; ++r2) {
            unordered_map<ll, int> sum_count;
            sum_count[0] = 1;

            for (int col = 1; col <= n; ++col) {
                ll current_sum = prefix_sum[r2][col] - prefix_sum[r1-1][col];

                ll mod_sum = current_sum % 9;
                if (mod_sum < 0) mod_sum += 9;

                if (sum_count.find(mod_sum) != sum_count.end()) {
                    beautiful_count += sum_count[mod_sum];
                }

                sum_count[mod_sum]++;
            }
        }
    }

    return beautiful_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    int result = countBeautifulSubmatrices(matrix, m, n);
    cout << result << '\n';
    
    return 0;
}
