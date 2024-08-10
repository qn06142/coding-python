#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> positions(n);

    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    int median = positions[n / 2];

    long long total_distance = 0;
    for (int i = 0; i < n; i++) {
        total_distance += abs(positions[i] - median);
    }

    cout << total_distance << endl;

    return 0;
}