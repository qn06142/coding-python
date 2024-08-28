#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500;
int gold[MAXN][MAXN], silver[MAXN][MAXN];
int prefix_gold[MAXN][MAXN], prefix_silver[MAXN][MAXN];
int max_gold_row[MAXN][MAXN], max_silver_col[MAXN][MAXN];

int main() {
    int m, n;
    cin >> m >> n;

    // Input for gold and silver
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> gold[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> silver[i][j];

    // Compute prefix sums for gold (leftward sums)
    for (int i = 0; i < m; i++) {
        prefix_gold[i][0] = gold[i][0];
        for (int j = 1; j < n; j++)
            prefix_gold[i][j] = prefix_gold[i][j-1] + gold[i][j];
    }

    // Compute prefix sums for silver (upward sums)
    for (int j = 0; j < n; j++) {
        prefix_silver[0][j] = silver[0][j];
        for (int i = 1; i < m; i++)
            prefix_silver[i][j] = prefix_silver[i-1][j] + silver[i][j];
    }

    // Calculate max gold row-wise
    for (int i = 0; i < m; i++) {
        max_gold_row[i][0] = prefix_gold[i][0];
        for (int j = 1; j < n; j++) {
            max_gold_row[i][j] = max(max_gold_row[i][j-1], prefix_gold[i][j]);
        }
    }

    // Calculate max silver column-wise
    for (int j = 0; j < n; j++) {
        max_silver_col[0][j] = prefix_silver[0][j];
        for (int i = 1; i < m; i++) {
            max_silver_col[i][j] = max(max_silver_col[i-1][j], prefix_silver[i][j]);
        }
    }

    // Calculate maximum value
    int max_value = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Max value from gold ending at (i,j) and silver not overlapping
            int value = max_gold_row[i][j] + max_silver_col[i][j];
            max_value = max(max_value, value);
        }
    }

    // Output the result
    cout << max_value << endl;

    return 0;
}
