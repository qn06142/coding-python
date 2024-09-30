#include <iostream>
#include <vector>

using namespace std;

const int MAX_X = 1005;  
const int MAX_Y = 1005;  
bool grid[MAX_X][MAX_Y]; 

int bruteForce(const vector<tuple<int, int, int>> &rectangles) {

    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            grid[i][j] = false;
        }
    }

    for (const auto &rect : rectangles) {
        int i = get<0>(rect);
        int j = get<1>(rect);
        int k = get<2>(rect);

        for (int x = i; x < j; x++) {   
            for (int y = 0; y < k; y++) { 
                grid[x][y] = true;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            if (grid[i][j]) {
                area++;
            }
        }
    }

    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;  
    cin >> n;

    vector<tuple<int, int, int>> rectangles(n);

    for (int idx = 0; idx < n; idx++) {
        int i, j, k;
        cin >> i >> j >> k;
        rectangles[idx] = {i, j, k};
    }

    int bruteForceArea = bruteForce(rectangles);

    cout << bruteForceArea << endl;

    return 0;
}