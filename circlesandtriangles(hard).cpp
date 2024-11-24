#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long

long long countValidTriangles(int n, int L, vector<int>& positions) {
    // Sort the positions for easier distance calculation
    sort(positions.begin(), positions.end());

    long long totalTriangles = (long long)n * (n - 1) * (n - 2) / 6;
    long long invalidTriangles = 0;

    int semilen = (L + 1) / 2; // L/2 rounded up

    for (int i = 0; i < n; ++i) {
        if (positions[i] <= L / 2) {
            long long it = lower_bound(positions.begin(), positions.end(), positions[i] + semilen) - positions.begin() - (i + 1);
            invalidTriangles += it * (it - 1) / 2;
        } else {
            long long it = n - i + lower_bound(positions.begin(), positions.end(), positions[i] - L / 2) - positions.begin() - 1;
            invalidTriangles += it * (it - 1) / 2;
        }
    }

    return totalTriangles - invalidTriangles;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, L;
    cin >> n >> L;
    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    // Calculate the number of valid triangles
    long long result = countValidTriangles(n, L, positions);
    cout << result << endl;

    return 0;
}
