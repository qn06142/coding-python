#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> segments(n);

    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        if (x > y) swap(x, y); 
        segments[i] = {x, y};
    }

    sort(segments.begin(), segments.end());

    long long maxLength = 0;
    long long start = segments[0].first;
    long long end = segments[0].second;

    for (int i = 1; i < n; i++) {
        if (segments[i].first <= end) {

            end = max(end, segments[i].second);
        } else {

            maxLength = max(maxLength, end - start);

            start = segments[i].first;
            end = segments[i].second;
        }
    }

    maxLength = max(maxLength, end - start);

    cout << maxLength << "\n";

    return 0;
}