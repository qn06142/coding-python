#include <bits/stdc++.h>
using namespace std;

bool isValid(const vector<pair<int, int>>& cards, vector<int>& top, vector<int>& bottom) {
    for (int i = 1; i < bottom.size(); ++i) {
        if (bottom[i] >= bottom[i - 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i].first >> cards[i].second; 
    }

    int minFlips = INT_MAX;

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<pair<int, int>> temp(cards);
        int flips = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                swap(temp[i].first, temp[i].second); 
                ++flips;
            }
        }

        sort(temp.begin(), temp.end());

        vector<int> top(n), bottom(n);
        for (int i = 0; i < n; ++i) {
            top[i] = temp[i].first;
            bottom[i] = temp[i].second;
        }

        if (isValid(temp, top, bottom)) {
            minFlips = min(minFlips, flips);
        }
    }

    if (minFlips == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << minFlips << '\n';
    }

    return 0;
}