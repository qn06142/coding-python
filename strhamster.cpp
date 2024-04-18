#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    char x, y;
    cin >> x >> y;

    vector<int> x_positions, y_positions;
    for (int i = 0; i < n; i++) {
        if (s[i] == x) x_positions.push_back(i);
        if (s[i] == y) y_positions.push_back(i);
    }

    int max_time = 0;
    for (auto x_pos : x_positions) {
        int min_time = n;
        for (auto y_pos : y_positions) {
            int time = min(abs(x_pos - y_pos), n - abs(x_pos - y_pos));
            min_time = min(min_time, time);
        }
        max_time = max(max_time, min_time);
    }

    cout << max_time << endl;

    return 0;
}
