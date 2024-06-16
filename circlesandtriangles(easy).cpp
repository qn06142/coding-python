#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countValidTriangles(int n, int L, vector<int>& positions) {
    // Sort the positions for easier distance calculation
    sort(positions.begin(), positions.end());
    int totalTriangles = 0;

    // Triple nested loops to iterate over all possible triplets
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                // Calculate the angular distances
                int d1 = (positions[j] - positions[i] + L) % L;
                int d2 = (positions[k] - positions[j] + L) % L;
                int d3 = (positions[i] - positions[k] + L) % L;
                // The sum of distances should be L, and we want to check the maximum distance
                int maxDistance = max({d1, d2, d3});
                if (maxDistance <= L / 2) {
                    totalTriangles += 1;
                }
            }
        }
    }

    return totalTriangles;
}

int main() {
    int n, L;
    cin >> n >> L;
    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    // Calculate the number of valid triangles
    int result = countValidTriangles(n, L, positions);
    cout << result << endl;

    return 0;
}
