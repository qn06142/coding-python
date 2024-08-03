#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& arr) {
    vector<int> dp;
    for (int num : arr) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }
    return dp.size();
}

void generateSegments(const string& s, int start, vector<int>& current, int& maxLIS) {
    if (start == s.size()) {
        maxLIS = max(maxLIS, LIS(current));
        return;
    }
    long long num = 0;
    for (int i = start; i < s.size(); ++i) {
        num = num * 10 + (s[i] - '0');
        if (num > INT_MAX) break; 
        current.push_back(num);
        generateSegments(s, i + 1, current, maxLIS);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> current;
    int maxLIS = 0;
    generateSegments(s, 0, current, maxLIS);

    cout << maxLIS << endl;

    return 0;
}