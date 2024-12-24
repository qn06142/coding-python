#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[4][10005]; 
int dp[10005][16];

int calculate_mask_sum(int col, int mask) {
    int sum = 0;
    for (int row = 0; row < 4; ++row) {
        if (mask & (1 << row)) {
            sum += a[row][col];
        }
    }
    return sum;
}

bool is_valid_mask(int mask) {
    for (int row = 0; row < 3; ++row) {
        if ((mask & (1 << row)) && (mask & (1 << (row + 1)))) {
            return false;
        }
    }
    return true;
}

bool is_valid_transition(int prev_mask, int curr_mask) {
    return ((prev_mask & curr_mask) == 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int col = 0; col < n; ++col) {
        for (int mask = 0; mask < 16; ++mask) {
            dp[col][mask] = LLONG_MIN;
        }
    }

    for (int mask = 0; mask < 16; ++mask) {
        if (is_valid_mask(mask)) {
            dp[0][mask] = calculate_mask_sum(0, mask);
        }
    }

    for (int col = 1; col < n; ++col) {
        for (int curr_mask = 0; curr_mask < 16; ++curr_mask) {
            if (!is_valid_mask(curr_mask)) continue;

            int curr_sum = calculate_mask_sum(col, curr_mask);
            for (int prev_mask = 0; prev_mask < 16; ++prev_mask) {
                if (is_valid_mask(prev_mask) && is_valid_transition(prev_mask, curr_mask)) {
                    dp[col][curr_mask] = max(dp[col][curr_mask], dp[col-1][prev_mask] + curr_sum);
                }
            }
        }
    }

    int result = LLONG_MIN;
    for (int mask = 0; mask < 16; ++mask) {
        if (is_valid_mask(mask)) {
            result = max(result, dp[n-1][mask]);
        }
    }

    assert(result != LLONG_MIN);
    cout << result << "\n";
    return 0;
}