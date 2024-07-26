#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
signed main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    int max_people = 0;
    int current_people = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {

        current_people += points[right].second;

        while (points[right].first - points[left].first > 2 * k) {
            current_people -= points[left].second;
            left++;
        }

        max_people = max(max_people, current_people);
    }

    cout << max_people << endl;

    return 0;
}