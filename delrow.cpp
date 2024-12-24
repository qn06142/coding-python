#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5; 
string grid[MAXN];

bool check(int rows, int r, int c) {
    set<vector<char>> store;

    for (int j = 0; j < c; j++) {
        vector<char> column;
        for (int i = rows; i < r; i++) {
            column.push_back(grid[i][j]);
        }
        if (store.count(column)) {
            return false; 
        }
        store.insert(column);
    }
    return true;
}

int solve(int r, int c) {
    int l_ = 0, r_ = r, ans = 0;
    while(l_ <= r_) {
        int mid = (l_ + r_) / 2;
        if(check(mid, r, c)) {
            ans = mid;
            l_ = mid + 1;
        } else r_ = mid - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    cout << solve(r, c) << '\n';
    return 0;
}