#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;

bool is_valid(const vector<int>& selected, const vector<string>& weights) {
    vector<int> digit_count(10, 0);

    for (int i : selected) {
        for (char c : weights[i]) {
            digit_count[c - '0']++;
            if (digit_count[c - '0'] > 2) return false; 
        }
    }
    return true;
}

signed main() {
    int n;
    cin >> n;
    vector<string> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        values[i] = stoi(weights[i]); 
    }

    int max_weight = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> selected;
        int current_weight = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                selected.push_back(i);
                current_weight += values[i];
            }
        }

        if (is_valid(selected, weights)) {
            max_weight = max(max_weight, current_weight);
        }
    }

    cout << max_weight << endl;
    return 0;
}