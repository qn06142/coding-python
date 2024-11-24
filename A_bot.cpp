#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N+1);
    vector<vector<int>> positions(100001);  

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        positions[a[i]].push_back(i);
    }

    while (Q--) {
        int l, r, x;
        cin >> l >> r >> x;

        vector<int> factors;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                factors.push_back(i);
                if (i != x / i) {
                    factors.push_back(x / i);
                }
            }
        }

        bool found = false;
        for (int f : factors) {
            int other_factor = x / f;
            if(f == other_factor) continue;
            if (positions[f].empty() || positions[other_factor].empty()) continue;

            auto it1 = lower_bound(positions[f].begin(), positions[f].end(), l);
            auto it2 = lower_bound(positions[other_factor].begin(), positions[other_factor].end(), l);

            if (it1 != positions[f].end() && *it1 <= r) {
                if (f != other_factor) {
                    if (it2 != positions[other_factor].end() && *it2 <= r) {
                        found = true;
                        break;
                    }
                } else {
                    auto it1_next = next(it1);
                    if (it1_next != positions[f].end() && *it1_next <= r) {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}