#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> queen_pos;

void printSolution() {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << (queen_pos[r] == c ? 1 : 0) << " ";
        }
        cout << "\n";
    }
    exit(0);
}

void solve(int row, long long col_mask, long long diag1_mask, long long diag2_mask) {
    if (row == n) printSolution();
    long long available = ((1LL << n) - 1) & ~(col_mask | diag1_mask | diag2_mask);
    while (available) {
        long long bit = available & -available; // rightmost set bit
        available ^= bit;
        int col = __builtin_ctzll(bit);
        queen_pos[row] = col;
        solve(row + 1,
              col_mask | bit,
              (diag1_mask | bit) << 1,
              (diag2_mask | bit) >> 1);
    }
}

int main() {
    cin >> n;
    queen_pos.resize(n);
    solve(0, 0, 0, 0);
}
