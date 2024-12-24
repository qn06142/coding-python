#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<pair<int, int>> &lines) {
    if (lines.empty()) return 0;

    sort(lines.begin(), lines.end());

    int ans = 0;
    int start = lines[0].first;
    int end = lines[0].second;

    for (size_t i = 1; i < lines.size(); ++i) {
        if (lines[i].first <= end) {

            end = max(end, lines[i].second);
        } else {

            ans += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
    }

    ans += end - start;

    return ans;
}

int main() {
    int n;
    cin >> n; 
    vector<pair<int, int>> lines(n);

    for (int i = 0; i < n; ++i) {
        cin >> lines[i].first >> lines[i].second; 
    }

    cout << calc(lines) << endl;

    return 0;
}