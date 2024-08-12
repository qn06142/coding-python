#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);  
        intervals[i] = {a, b};
    }

    sort(intervals.begin(), intervals.end());

    int max_len = 0, L = -1, H = -1;
    int current_start = intervals[0].first;
    int current_end = intervals[0].second;

    for (int i = 1; i < n; i++) {
        int a = intervals[i].first, b = intervals[i].second;
        if (a <= current_end) {
            current_end = max(current_end, b);
        } else {
            int length = current_end - current_start;
            if (length > max_len) {
                max_len = length;
                L = current_start;
                H = current_end;
            }
            current_start = a;
            current_end = b;
        }
    }

    int length = current_end - current_start;
    if (length > max_len) {
        max_len = length;
        L = current_start;
        H = current_end;
    }

    cout << L << " " << H << endl;

    return 0;
}