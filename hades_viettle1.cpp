#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> islands(n);

    for (int i = 0; i < n; i++) {
        cin >> islands[i].second >> islands[i].first;
    }

    int max_population = 0;

    for (int i = 0; i < n; i++) {
        int current_population = 0;
        for (int j = 0; j < n; j++) {
            if (abs(islands[j].first - islands[i].first) <= k) {
                current_population += islands[j].second;
            }
        }
        max_population = max(max_population, current_population);
    }

    cout << max_population << endl;
    return 0;
}