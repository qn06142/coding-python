#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLIS(vector<pair<int, int>> &cells) {
    vector<int> dp; 
    for (auto &[row, col] : cells) {
        auto it = upper_bound(dp.begin(), dp.end(), col);
        if (it == dp.end()) {
            dp.push_back(col);
        } else {
            *it = col;
        }
    }
    return dp.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, Q, K;
    cin >> N >> M >> Q >> K;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<pair<int, int>>> mgroup(K);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int val = grid[i][j] % K;
            mgroup[val].emplace_back(i, j);
        }
    }

    vector<int> results(K);
    for (int i = 0; i < K; ++i) {
        results[i] = findLIS(mgroup[i]);
    }
    while(Q--) {
        int x;
        cin >> x;
        cout << results[x] << '\n';
    }

    return 0;
}