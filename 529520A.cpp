#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int countPairs(int l, int r, int n) {
    int total_pairs = (1LL * (r - l + 1) * (r - l + 2) / 2) % MOD;
    int invalid_pairs = 0;
    
    for (int k = n; k <= r; k += n) {
        int low = max(l, k);
        int high = r;
        if (low <= high) {
            int count = (high / k) - (low - 1) / k;
            invalid_pairs = (invalid_pairs + 1LL * count * (count + 1) / 2) % MOD;
        }
    }
    
    int result = (total_pairs - invalid_pairs + 1 + MOD) % MOD;
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r, n;
        cin >> l >> r >> n;
        cout << countPairs(l, r, n) << "\n";
    }
    return 0;
}
