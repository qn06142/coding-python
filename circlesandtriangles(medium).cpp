#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int countValidTriangles(int n, int L, vector<int>& positions) {
    // Sort the positions for easier distance calculation
    sort(positions.begin(), positions.end());
    int totalTriangles = 0;

    // Extend the positions vector to handle circular nature
    for (int i = 0; i < n; ++i) {
        positions.push_back(positions[i] + L);
    }
    
    int semilenfloor = L / 2;
    int semilenceil = ceil((double)L / 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if((positions[j] - positions[i]) * 2 <= L) {
            // Use the extended positions to find the upper bound of the valid range
            int pos_i = positions[i];
            int pos_j = positions[j];
            int max_pos_i = pos_i + semilenceil;
            int max_pos_j = pos_j + semilenfloor;
            auto it1 = lower_bound(positions.begin(), positions.end(), max_pos_i);
            auto it = upper_bound(positions.begin(), positions.end(), max_pos_j);
            //cout << pos_i << ' ' << max_pos_i << ' ' << pos_j << ' ' << max_pos_j << endl;
            //cout << it - positions.begin() << ' ' << it1 - positions.begin() << endl;
            //cout << endl;
            // We need to count points between j and k-1, excluding i and j themselves
            totalTriangles += it - it1;
            }
        }
    }

    return totalTriangles;
}

int main() {
    int n, L;
    cin >> n >> L;
    vector<int> positions(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
        positions[i + n] = positions[i] + L;
    }

    // Calculate the number of valid triangles
    int result = countValidTriangles(n, L, positions);
    cout << result / 2 << endl;

    return 0;
}
