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
int bacctracc(int i, int prev_mask, int sum) {
    if(i == n) {
        return sum;
    }
    if(dp[i][prev_mask] != LLONG_MAX) return dp[i][prev_mask];
    int ans = LLONG_MAX;
    for(int mask = 0; mask < 16; mask++) {
        if(is_valid_mask(mask) and is_valid_transition(mask, prev_mask)) {
            ans = max(ans, calculate_mask_sum(i, mask));
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < 4; ++i) {
            cin >> a[i][j];
        }
    }


    return 0;
}