#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    
    int N, M;
    cin >> N >> M;

    map<int, int> changes; 

    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;

        if (L <= R) {
            changes[L]++;
            changes[R + 1]--;
        } else {
            changes[L]++;
            changes[1]++;
            changes[R + 1]--;
        }
    }

    
    int current_coins = 0;
    int max_coins = 0, max_count = 0;
    for (auto it = changes.begin(); it != changes.end(); ++it) {
        current_coins += it->second;
        max_coins = max(max_coins, current_coins);
    }

    
    current_coins = 0;
    for (auto it = changes.begin(); it != changes.end(); ++it) {
        current_coins += it->second;
        if (current_coins == max_coins) {
            auto next_it = next(it);
            int range_length = (next_it != changes.end() ? next_it->first - it->first : N - it->first + 1);
            max_count += range_length;
        }
    }

    cout << max_coins << " " << max_count << "\n";

    return 0;
}
