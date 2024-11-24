#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n));

    int value = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = value++;
        }
    }

    vector<pair<char, vector<int>>> operations(k);
    for (int i = 0; i < k; ++i) {
        char type;
        int a, b, c, d;
        cin >> type >> a >> b >> c >> d;
        operations[i] = {type, {a - 1, b - 1, c - 1, d - 1}};
    }

    for (int i = k - 1; i >= 0; --i) {
        char type = operations[i].first;
        int a = operations[i].second[0];
        int b = operations[i].second[1];
        int c = operations[i].second[2];
        int d = operations[i].second[3];

        if (type == 'H') {

            for (int x = a; x <= c; ++x) {
                for (int y1 = b, y2 = d; y1 < y2; ++y1, --y2) {
                    swap(grid[x][y1], grid[x][y2]);
                }
            }
        } else if (type == 'V') {

            for (int y = b; y <= d; ++y) {
                for (int x1 = a, x2 = c; x1 < x2; ++x1, --x2) {
                    swap(grid[x1][y], grid[x2][y]);
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}