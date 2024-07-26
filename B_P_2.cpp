#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

bool isGood(const vector<int>& a, int left, int right) {
    if (left >= right) {
        return true;
    }

    unordered_map<int, int> frequency;
    set<pair<int, int>> freqSet;

    for (int i = left; i <= right; ++i) {
        frequency[a[i]]++;
    }
    for (const auto& [num, freq] : frequency) {
        freqSet.insert({freq, num});
    }

    while (!freqSet.empty()) {
        auto leastFreq = *freqSet.begin();
        int leastElement = leastFreq.second;
        int leastCount = leastFreq.first;

        if (leastCount != 1) {
            return false;
        }

        int splitPoint = -1;
        for (int i = left; i <= right; ++i) {
            if (a[i] == leastElement) {
                splitPoint = i;
                break;
            }
        }

        if (splitPoint == -1) {
            return false;
        }

        frequency[leastElement]--;
        freqSet.erase(leastFreq);

        if (frequency[leastElement] > 0) {
            freqSet.insert({frequency[leastElement], leastElement});
        }

        return isGood(a, left, splitPoint - 1) && isGood(a, splitPoint + 1, right);
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (isGood(a, 0, n - 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}