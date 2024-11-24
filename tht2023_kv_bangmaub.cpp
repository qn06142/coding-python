#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> board(m, vector<int>(n, 0));
    for(int i = 0; i < k; i++) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        for(int x = x1; x <= x2; x++) {
            for(int y = y1; y <= y2; y++) {
                board[x-1][y-1] = c;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
