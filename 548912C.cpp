#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#pragma GCC target("arch=skylake")
#pragma GCC optimize("Ofast,fast-math")
int bit(int x, int y) {
    return __builtin_popcount(x ^ y);  
}
int a[(int) 1e6 + 5];
int f[25][(1 << 20) + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;

    for (int j = 0; j < n; ++j) {

        int head_j = a[j] >> 10;  
        int tail_j = a[j] & ((1 << 10) - 1);  

        for (int mask = 0; mask < (1 << 10); ++mask) {
            int diff = bit(mask, tail_j);  
            if (diff <= k) {

                int remaining_diff = k - diff;
                ans += f[remaining_diff][(head_j << 10) + mask];  
            }
        }

        for (int first = 0; first < (1 << 10); ++first) {
            int diff_head = bit(first, head_j);
            f[diff_head][(first << 10) + tail_j]++;  
        }
    }

    cout << ans << endl;
    return 0;
}