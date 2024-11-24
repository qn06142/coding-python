#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int lis(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> bIndex(n);
    map<int, int> bMap;

    for (int i = 0; i < n; ++i) {
        bMap[b[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        bIndex[i] = bMap[a[i]];
    }

    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), bIndex[i]);
        if (it == lis.end()) {
            lis.push_back(bIndex[i]);
        } else {
            *it = bIndex[i];
        }
    }

    return lis.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    cout << lis(a, b) << endl;

    return 0;
}