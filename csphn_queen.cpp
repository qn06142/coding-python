#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int n, result = 0;
vector<int> column; 

bool canPlace(int row, int col) {
    for (int i = 0; i < row; ++i) {

        if (column[i] == col || abs(column[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row) {
    if (row == n) {

        ++result;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (canPlace(row, col)) {
            column[row] = col; 
            solve(row + 1);    
        }
    }
}

int main() {

    cin >> n;
    column.resize(n);

    solve(0); 

    cout << result << endl;

    return 0;
}