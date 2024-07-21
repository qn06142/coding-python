#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void knapsack(int n, int m, const vector<int>& weights, const vector<int>& values) {

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= m; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int max_value = dp[n][m];

    vector<int> items_taken;
    int w = m;
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            items_taken.push_back(i);
            w -= weights[i-1];
        }
    }

    cout << max_value << endl;
    cout << items_taken.size() << endl;
    for (size_t i = 0; i < items_taken.size(); ++i) {
        if (i > 0) cout << " ";
        cout << items_taken[i];
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    knapsack(n, m, weights, values);

    return 0;
}